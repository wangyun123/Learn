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

Mat g_img1;
Mat g_img2;
Mat g_merge;
double g_alpha;
double g_beta;
int g_scrollbarPos = 50;
int g_scrollbarSize=100;

void onTrackbar(int, void*)
{
	g_alpha = (double)g_scrollbarPos / g_scrollbarSize;
	g_beta = 1.0 - g_alpha;
	addWeighted(g_img1, g_alpha, g_img2, g_beta, 0.0, g_merge);
	imshow("windows", g_merge);
}
int main()
{
	g_img1 = imread("1.jpg");
	g_img2 = imread("2.jpg");
	if (!g_img1.data)
	{
		printf("can't open the image 1\n");
		return -1;
	}
	
	if (!g_img2.data)
	{
		printf("can't open the image 2\n");
		return -1;
	}

	namedWindow("windows");
	createTrackbar("trackbar", "windows", &g_scrollbarPos, g_scrollbarSize, onTrackbar);
	//namedWindow
	//imshow("test image", img);
	waitKey(0);

	return 0;
}