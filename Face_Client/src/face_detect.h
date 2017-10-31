#ifndef FACE_DETECT_H_INCLUDED
#define FACE_DETECT_H_INCLUDED

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;



string process(string path)
{
    Mat mat;
    mat=imread(path);resize(mat,mat,Size(358,441));
    std::vector<uchar> data_encode;
    imencode(".bmp", mat, data_encode);
    std::string str_encode(data_encode.begin(), data_encode.end());
    cout<<str_encode.size()<<endl;
    //std::string res=to_string(str_encode.size())+":"+str_encode;
    cout<<path<<endl;
    return str_encode;;
}

void get_face(const string& res)
{
    cout<<"come in"<<endl;
    Mat img_decode;
    std::string str_tmp = res;
    std::vector<uchar> data(str_tmp.begin(), str_tmp.end());
    img_decode = imdecode(data,1);
    imshow("pic",img_decode);
}



#endif // FACE_DETECT_H_INCLUDED
