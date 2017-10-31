#include "wcdCFacerecognize.h"

wcdCFacerecognize::wcdCFacerecognize()
{

}

wcdCFacerecognize::wcdCFacerecognize(FR_FaceDetectCallBack FFCB,FR_FaceVerifyCallBack MFCB,string path,string prototxt,string caffemodel,string haar_xml,int userdata)
{
    head_path = path;
	m_name = LoadName(head_path + "/data/Name.txt");
	m_features = LoadFaceMatrix(m_name);

	g_pFaceDetectFunc = FFCB;
	g_pFaceVerifyFunc = MFCB;
	UserData = userdata;

	ex=new ExtractFeature(prototxt,caffemodel);

	faceCascade.load(haar_xml);
}

int wcdCFacerecognize::m_AddVerifyTarget(string VTGUID, Mat iptFrame)
{
    if(iptFrame.empty())
    {
        cout<<"Mat is empty(func m_AddVerifyTarget)"<<endl;
        return -1;
    }

    Mat img=iptFrame;

    vector<Mat> faces=FaceDetect(img);

    if(faces.size()>1)
    {
       cout<<"Too much faces(func m_AddVerifyTarget)"<<endl;
       return -1;
    }
    else if(faces.size()==0)
        return -1;

    vector<float> feature;
    feature=ex->Extract(faces[0]);

    if(feature.size()==0)
    {
        cout<<"Can not extract feature(func m_AddVerifyTarget)"<<endl;
        return -1;
    }


    string name(VTGUID);
	vector<string>::iterator it = find(m_name.begin(), m_name.end(), name);
	if (it != m_name.end())
	{
		cout << "Name existed,please use others!(Func m_AddVerifyTarget)" << endl;
		return -1;
	}

	Mat saveFeature = Vector2dToMat(feature);
	SaveName(name, head_path + "/data/Name.txt");
	SaveMat(saveFeature, head_path + string("/data/") + name + ".xml");

	cout << "ADD No." << name << " to database successfully!" << endl;
	return 0;

}

int wcdCFacerecognize::m_DelVerifyTarget(string VTGUID)
{
    if (VTGUID.size()==0)
	{
		cout << "GUID is empty(Func FR_DelVerifyTarget)" << endl;
		return -1;
	}
	string name(VTGUID);
	string temp_path=head_path + "/data/Name.txt";
	ifstream in(temp_path.c_str());

	if (!in)
	{
		cout << "Can't open file(Func m_DelVerifyTarget)" << endl;
		return -1;
	}

	string s;
	vector<string> name_;
	while (getline(in, s))
		name_.push_back(s);
    int sz=name_.size();
	vector<string>::iterator it;
	for (it = name_.begin(); it != name_.end();++it)
	{
		if (*it == name)
		{
			name_.erase(it);
			break;
		}
	}

	if (it == name_.end()&&name_.size()==sz)
	{
		cout << "GUID doesn't exist!(Func FR_DelVerifyTarget)" << endl;
		return -1;
	}
	in.close();

    temp_path=head_path + "/data/Name.txt";
	ofstream out(temp_path.c_str());
	for (int i = 0; i < name_.size(); i++)
		out << name_[i] << endl;

	remove((head_path + string("/data/") + name + ".xml").c_str());

	cout << "Delete No." << name << " from database successfully!" << endl;
	return 0;
}

int wcdCFacerecognize::m_ClearVerifyTarget()
{
    int ret = 0;
	for (int i = 0; i < m_name.size(); i++)
	{
		ret = m_DelVerifyTarget((m_name[i]).c_str());
		if (ret == -1)
			return -1;
	}

	cout << "Delete all successfully!" << endl;
	return 0;
}

int wcdCFacerecognize::m_FaceDetect(Mat iptFrame)
{
    vector<Rect> face_rect = FaceDetect(iptFrame, 0);
	if (face_rect.size() == 0)
	{
		cout << "Can't detect face!(Func FR_FaceDetect)" << endl;
		return -1;
	}
	vector<uchar> detect_face;
	int length;
	for (int i = 0; i < face_rect.size(); i++)
	{
		imencode(".bmp", iptFrame(face_rect[i]), detect_face);
		length = (int)detect_face.size();
		if (g_pFaceDetectFunc)
		{
			(*g_pFaceDetectFunc)(to_string(i).c_str(), &detect_face[0], length*sizeof(uchar), face_rect[i].x, face_rect[i].y, face_rect[i].width, face_rect[i].height, UserData);
		}
	}
	return 0;
}

int wcdCFacerecognize::m_FaceListVerify(Mat iptFrame, string& VTGUID)
{
    vector<Mat> detect_face = FaceDetect(iptFrame);

	if (detect_face.empty())
	{
		cout << "image has no face1(Func m_Multi_FaceListVerify)" << endl;
		return -1;
	}

	vector<float> feature;
	int id = 0;
	float max = 0;

	for (int j = 0; j < detect_face.size(); j++)
	{
		feature = ex->Extract(detect_face[j]);

		if (feature.size() == 0)
		{
			cout << "Image "<<j<<" can't extract feature!(Func m_Multi_FaceListVerify)" << endl;
			continue;
		}

		id = 0;
		max = 0;

		for (int i = 1; i < m_features.size() + 1; i++)
		{
			float rate = cosine(feature, m_features[i - 1]);
			if (rate > 0.90)
			{
				if (rate > max)
				{
					max = rate;
					id = stoi(m_name[i - 1]);
				}

			}

		}

		if (id == 0)
			cout << "num " << j << " : " << "no recognized face!" << endl;
		else
		{
			string path = string(head_path + "/registerimg/") + to_string(id) + ".bmp";
			Mat face = imread(path);
			vector<uchar> v;
			imencode(".bmp", face, v);
			//int length = (int)v.size();
			//if (g_pFaceVerifyFunc)
			//	(*g_pFaceVerifyFunc)(to_string(id).c_str(), to_string(id).c_str(), &v[0], length*sizeof(uchar), (int)(max * 100), UserData);
			//string res=to_string(id);
			return id;
		}

	}

	return -1;
}

void wcdCFacerecognize::Caffe_Init()
{
    ex->Caffe_Predefine();
}



vector<Mat> wcdCFacerecognize::FaceDetect(Mat iptFrame)
{
    if(iptFrame.empty())
    {
        cout<<"Mat is empty(func FaceDetect)"<<endl;
        return iptFrame;
    }

    Mat imgGray,img=iptFrame;
    vector<Rect> faces;
    vector<Mat> res;

    if(img.channels() ==3)
    {
       cvtColor(img, imgGray, CV_RGB2GRAY);
    }
    else
    {
       imgGray = img;
    }

    faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));

    if(faces.size()==0)
    {
        cout<<"No face!(func FaceDetect)"<<endl;
        return res;
    }


    if(faces.size()>0)
    {
       Mat mat;
       for(int i =0; i<faces.size(); i++)
       {
           mat=img(faces[i]);
           resize(mat, mat, Size(224, 224));
           res.push_back(mat);
       }
    }

    return res;

}

vector<Rect> wcdCFacerecognize::FaceDetect(Mat iptFrame,int flag)
{
    if(iptFrame.empty())
    {
        cout<<"Mat is empty(func FaceDetect1)"<<endl;
        return iptFrame;
    }

    Mat imgGray,img=iptFrame;
    vector<Rect> faces;

    if(img.channels() ==3)
    {
       cvtColor(img, imgGray, CV_RGB2GRAY);
    }
    else
    {
       imgGray = img;
    }

    faceCascade.detectMultiScale(imgGray, faces, 1.2, 6, 0, Size(0, 0));

    if(faces.size()==0)
    {
        cout<<"No face!(func FaceDetect1)"<<endl;
        return faces;
    }


    return faces;

}

Mat wcdCFacerecognize::Vector2dToMat(vector<float> feature)
{
    Mat T(1, 4096, CV_32F);
	for (int i = 0; i < feature.size(); i++)
	{
		T.at<float>(0, i) = feature[i];
	}
	return T;
}

void wcdCFacerecognize::SaveMat(Mat &saveFeature, const string& filename)
{
    FileStorage fs(filename, FileStorage::WRITE);
	if (!fs.isOpened())
	{
		cout << "Can't open file,please input right path!(Func SaveMat)" << endl;
		return;
	}

	fs << "FaceMatrix" << saveFeature;
	fs.release();
}

void wcdCFacerecognize::SaveName(const string& name, const string& filename)
{

    ofstream out_(filename.c_str(), ofstream::app);
	if (!out_)
	{
		cout << "Can't open file,please input right path!(Func SaveName)" << endl;
		return;
	}
	out_ << name << endl;
}

float wcdCFacerecognize::cosine(const vector<float>& v1, const vector<float>& v2)
{
    assert(v1.size() == v2.size());
	float f = 0.0;
	if ((module(v1) * module(v2)) == 0)
		f = 0;
	else
		f = dotProduct(v1, v2) / (module(v1) * module(v2));
	return f;
}


float wcdCFacerecognize::dotProduct(const vector<float>& v1, const vector<float>& v2)
{
    assert(v1.size() == v2.size());
	float ret = 0.0;
	for (vector<float>::size_type i = 0; i != v1.size(); ++i)
	{
		if (v1[i] > 1000 || v2[i] > 1000 || v1[i] < (-1000) || v2[i] < (-1000))
			continue;
		else if (!(isnan(v1[i]) || isnan(v2[i])))
			ret += v1[i] * v2[i];
	}
	return ret;
}

float wcdCFacerecognize::module(const vector<float>& v)
{
    float ret = 0.0;
	for (vector<float>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i] > 1000 || v[i]<(-1000))
			continue;
		else if (!isnan(v[i]))
			ret += v[i] * v[i];
	}
	return sqrt(ret);
}

vector<string> wcdCFacerecognize::LoadName(const string& filename)
{
    vector<string> name;
	ifstream in(filename.c_str());
	if (!in)
	{
		cout << "Can't open file,please input right path!(Func LoadName)" << endl;
		return name;
	}
	string s;

	while (getline(in, s))
		name.push_back(s);
	return name;
}

Mat wcdCFacerecognize::LoadMat(const string& file)
{
    Mat FaceMatrix_;
	FileStorage fs(file, FileStorage::READ);
	if (!fs.isOpened())
	{
		cout << "Can't open file,please input right path!(Func LoadMat)" << endl;
		return FaceMatrix_;
	}

	fs["FaceMatrix"] >> FaceMatrix_;
	return FaceMatrix_;
}

vector<float> wcdCFacerecognize::Mat2vector(Mat &FaceMatrix_mat)
{
    vector<float> v;
	for (int i = 0; i < FaceMatrix_mat.rows; ++i)
		for (int j = 0; j < FaceMatrix_mat.cols; ++j)
			v.push_back(FaceMatrix_mat.at<float>(i, j));
	return v;
}

vector<vector<float> > wcdCFacerecognize::LoadFaceMatrix(vector<string> NameVector)
{
    vector<vector<float> > features;
	for (int i = 0; i < NameVector.size(); i++)
	{
		string path = head_path + string("/data/") + NameVector[i] + ".xml";
		Mat feature = LoadMat(path);
		vector<float> feature_ = Mat2vector(feature);
		features.push_back(feature);

	}
	return features;
}

string wcdCFacerecognize::to_string(int m_num)
{
    ostringstream os;
    os<<m_num;
    return os.str();
}

int wcdCFacerecognize::stoi(string s)
{
    istringstream is(s);
    int res;
    is>>res;
    return res;
}











