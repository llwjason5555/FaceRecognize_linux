#ifndef WCDCFACERECOGNIZE_H_INCLUDED
#define WCDCFACERECOGNIZE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include "ExtractFeature.h"

typedef unsigned char BYTE;

typedef bool(* FR_FaceDetectCallBack)(const char* FaceGUID, BYTE* FacePhoto, int FacePhotoLen, int OutX, int OutY, int OutW, int OutH, int UserData);

typedef bool(*FR_FaceVerifyCallBack)(const char* FaceGUID, const char* MatchGUID, BYTE* MatchPhoto, int MatchPhotoLen, int MatchDegree, int UserData);

class wcdCFacerecognize
{
public:
    wcdCFacerecognize();

    wcdCFacerecognize(FR_FaceDetectCallBack FFCB,FR_FaceVerifyCallBack MFCB,string path,string prototxt,string caffemodel,string haar_xml,int userdata);

    int m_AddVerifyTarget(string VTGUID, Mat iptFrame);

	int m_DelVerifyTarget(string VTGUID);

	int m_ClearVerifyTarget();

    int m_FaceDetect(Mat iptFrame);

    int m_FaceListVerify(Mat iptFrame, string& VTGUID);

    void Caffe_Init();

private:
    string head_path;
	vector<string> m_name;
	vector<vector<float> > m_features;
	int UserData;

	FR_FaceDetectCallBack g_pFaceDetectFunc ;
	FR_FaceVerifyCallBack g_pFaceVerifyFunc ;

	ExtractFeature *ex;

	CascadeClassifier faceCascade;

	vector<Mat> FaceDetect(Mat iptFrame);

	vector<Rect> FaceDetect(Mat iptFrame,int flag);

    Mat Vector2dToMat(vector<float> feature);

	void SaveMat(Mat &saveFeature, const string& filename);

	void SaveName(const string& name, const string& filename);

	float cosine(const vector<float>& v1, const vector<float>& v2);

	float dotProduct(const vector<float>& v1, const vector<float>& v2);

	float module(const vector<float>& v);

	vector<string> LoadName(const string& filename);

	Mat LoadMat(const string& file);

	vector<float> Mat2vector(Mat &FaceMatrix_mat);

	vector<vector<float> > LoadFaceMatrix(vector<string> NameVector);

	string to_string(int m_num);
	int stoi(string s);
};


#endif // WCDCFACERECOGNIZE_H_INCLUDED
