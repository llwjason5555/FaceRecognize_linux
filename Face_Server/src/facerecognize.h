#ifndef FACERECOGNIZE_H_INCLUDED
#define FACERECOGNIZE_H_INCLUDED

#include "wcdCFacerecognize.h"

#include <muduo/base/Types.h>
#include <muduo/base/StringPiece.h>

vector<Rect>g_vRect;
bool  FFCB(const char* FaceGUID, BYTE* FaceJpg, int FaceJpgLen, int OutX, int OutY, int OutW, int OutH, int UserData)
{
	Mat bufImage(1, FaceJpgLen, CV_8UC1);
	memcpy(bufImage.data, FaceJpg, FaceJpgLen);
	Mat MImageBGR = imdecode(bufImage, CV_LOAD_IMAGE_COLOR);//BMP解码
	imshow("image_FFCB", MImageBGR);
	waitKey(200);
	cout << "FaceGUID:" << FaceGUID << " OutX:" << OutX << " OutY:" << OutY << " OutW:" << OutW << " OutH:" << OutH << " UserData:" << UserData << endl;
	g_vRect.push_back(Rect(OutX, OutY, OutW, OutH));
	return true;
}
bool  MFCB(const char* FaceGUID, const char* MatchGUID, BYTE* MatchJpg, int MatchJpgLen, int MatchDegree, int UserData)
{
	Mat bufImage(1, MatchJpgLen, CV_8UC1);
	memcpy(bufImage.data, MatchJpg, MatchJpgLen);
	Mat MImageBGR = imdecode(bufImage, CV_LOAD_IMAGE_COLOR);//BMP解码
	imshow("image_MFCB", MImageBGR);
	waitKey(20);
	cout << "FaceGUID:" << FaceGUID << " MatchGUID:" << MatchGUID << " UserData:" << UserData <<"MatchDegree: "<< MatchDegree << endl;
	return true;
}

wcdCFacerecognize w(FFCB,MFCB,"/home/llw/Project/wcdCFacerecognize","/home/llw/Project/wcdCFacerecognize/VGG_FACE_deploy.prototxt","/home/llw/Project/wcdCFacerecognize/VGG_FACE.caffemodel","/home/llw/Project/wcdCFacerecognize/haarcascade_frontalface_alt2.xml",8);

void caffe_init()
{
    w.Caffe_Init();
    cout<<"Caffe Initialize Success!"<<endl;
}
std::string solveFacerec(const muduo::StringPiece& s)
{
    muduo::string str_tmp=s.as_string();
    cout<<str_tmp.size()<<endl;
    Mat img_decode;
    std::vector<uchar> data(str_tmp.begin(), str_tmp.end());
    img_decode = imdecode(data,1);
    if(img_decode.empty())
    {
        cout<<"accept error"<<endl;
        return NULL;
    }

    string VTGUID;
    int res=w.m_FaceListVerify(img_decode,VTGUID);
    //if(res.size()==0)
    //  return to_string(-1);
    //cout<<"face mat size :"<<res.size()<<endl;
    return to_string(res);
}

#endif // FACERECOGNIZE_H_INCLUDED
