#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

#ifdef _DEBUG
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#endif

int main()
{
	VideoCapture capture("pop.avi");

	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("video", frame);
		waitKey(10);
	}
//	return 0;
}