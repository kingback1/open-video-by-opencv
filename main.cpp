#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char**)
{
	VideoCapture cap("traffic.avi"); //open video filename
	if (!cap.isOpened())
		return -1;

	// ��ȡ����֡��
	long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);

	//��ȡ֡��  
	double rate = cap.get(CV_CAP_PROP_FPS);

	int delay = 1000 / rate;

	for (int i = 0; i<totalFrameNumber;i++)
	{
		Mat frame;
		cap >> frame;

		imshow("edges", frame);
		int c = waitKey(delay);

		//����ESC�˳���ȡ��Ƶ  
		if ((char)c == 27)
		{
			break;
		}

		//���°������ͣ���ڵ�ǰ֡���ȴ���һ�ΰ���  
		if (c >= 0 && c != 27)
		{
			waitKey(0);
		}

	}

	return 0;
}