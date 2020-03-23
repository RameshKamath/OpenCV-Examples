// Created By Ramesh Kamath
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

int main()
{
	// To work with just matrix create mask
	// create Matrix and store zeros for size(300, 600) with 8 bits for each Pixel.
	int Height = 300;
	int Width = 600;
	cv::Mat lineMask = cv::Mat::zeros(Height, Width, CV_8UC3);
	cv::Mat rectangleMask = cv::Mat::zeros(Height, Width, CV_8UC3);
	cv::Mat circleMask = cv::Mat::zeros(Height, Width, CV_8UC3);
	cv::Mat ellipseMask = cv::Mat::zeros(Height, Width, CV_8UC3);
	cv::Mat textMask = cv::Mat::zeros(Height, Width, CV_8UC3);
	cv::Mat polyMask = cv::Mat::zeros(Height, Width, CV_8UC3);

	// Draw lines on Matrix with options like x location, y location, color, line width, etc.
	cv::line(lineMask, cv::Point(100, 100), cv::Point(200, 200), cv::Scalar(255, 0, 0), 5);

	// Draw rectangle on Matrix with options like TopLeftlocation, BottomRightlocation, color,line width etc.
	cv::Point pTopLeft = cv::Point(100, 100);
	cv::Point pBottomRight = cv::Point(250, 200);
	cv::Rect rec = cv::Rect(pTopLeft, pBottomRight);
	cv::rectangle(rectangleMask, rec, cv::Scalar(0, 255, 128), 5);

	// Draw circles on Matrix with options like location, scale, color, etc.
	cv::circle(circleMask, cv::Point(250, 150), 100, cv::Scalar(0, 255, 128), -100);
	cv::circle(circleMask, cv::Point(350, 150), 100, cv::Scalar(255, 255, 255), -100);

	// Draw circles on Matrix with options like location, scale, color, etc.
	cv::RotatedRect box = cv::RotatedRect(cv::Point(100, 100), cv::Size2f(40, 50), 50.0);
	cv::ellipse(ellipseMask, box, cv::Scalar(0, 255, 128), 5);

	// Draw text on Matrix.
	cv::putText(textMask, "Text", cv::Point(100, 100), 2, 1.2, cv::Scalar(0, 255, 255), 5);

	// Draw Polyline
	std::vector<cv::Point> contour;
	contour.push_back(cv::Point(50, 50));
	contour.push_back(cv::Point(300, 50));
	contour.push_back(cv::Point(350, 200));
	contour.push_back(cv::Point(300, 150));
	contour.push_back(cv::Point(150, 350));
	contour.push_back(cv::Point(100, 100));
	const cv::Point *pts = (const cv::Point *)cv::Mat(contour).data;
	int npts = cv::Mat(contour).rows;

	polylines(polyMask, &pts, &npts, 1, false, cv::Scalar(0, 255, 0));

	// Display Matrix(image) in GUI.
	cv::imshow("Lines", lineMask);
	cv::imshow("Rectangle", rectangleMask);
	cv::imshow("Circles", circleMask);
	cv::imshow("Ellipse", ellipseMask);
	cv::imshow("Text", textMask);
	cv::imshow("PolyLine", polyMask);

	// wait with delay for any key from GUI.
	cv::waitKey(0);

	// free GUI things at before closing
	cv::destroyAllWindows();
	return 0;
}