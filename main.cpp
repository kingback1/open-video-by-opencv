#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char**)
{
	VideoCapture cap("traffic.avi"); //open video filename
	if (!cap.isOpened())
		return -1;

	// 获取整个帧数
	long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	
	//获取帧率  
	double rate = cap.get(CV_CAP_PROP_FPS);

	int delay = 1000 / rate;

	// 获得视频输入size
	Size size = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),    
		(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	VideoWriter video;
	video.open("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), rate, size, true);
	if (!video.isOpened())
	{
		return -1;
	}

	for (int i = 0; i<totalFrameNumber;i++)
	{
		Mat frame;
		cap >> frame;
		video << frame;

		imshow("edges", frame);
		int c = waitKey(delay);

		//按下ESC退出读取视频  
		if ((char)c == 27)
		{
			break;
		}

		//按下按键后会停留在当前帧，等待下一次按键  
		if (c >= 0 && c != 27)
		{
			waitKey(0);
		}

	}

	return 0;
}