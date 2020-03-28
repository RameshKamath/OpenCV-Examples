#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	// Create a black image of 500x300 size

	int Width = 500;
	int Height = 300;

	// initialize circle to be drawn
	cv::Point point = cv::Point(0, 0);
	cv::Color color = cv::Point(0, 0, 0);

	//mouse move location
	cv::Point move_point = cv::Point(0, 0);
	cv::Font font = cv::FONT_HERSHEY_SIMPLEX;

	cv::namedWindow('Draw', cv::WINDOW_NORMAL);
	cv::setMouseCallback('Draw', mouseClick);
	while (true)
	{
		cv::Mat Mask;
		Mask = cv::Zero
	}

	cv::destroyAllWindows();
	return 0;
}