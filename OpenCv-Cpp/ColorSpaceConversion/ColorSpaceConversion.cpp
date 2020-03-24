// Created By Ramesh Kamath
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
	std::string path;
	std::cout << "Give Path for Image: ";
	std::cin >> path;
	// Load Image to a Matrix
	cv::Mat image;
	image = cv::imread(path);

	// make sure data is loaded
	if (!image.data)
	{
		std::cout << "\nImage File data not loaded.\nExiting...";
		return -1;
	}

	// only Important color space conversions are given(Format is same of rest)

	// to RGB color space
	cv::Mat imageRGB;
	cv::cvtColor(image, imageRGB, cv::COLOR_BGR2RGB);

	// to RGBA color Space
	cv::Mat imageRGBA;
	cv::cvtColor(image, imageRGBA, cv::COLOR_BGR2RGBA);

	// to Gray color space
	cv::Mat imageGRAY;
	cv::cvtColor(image, imageGRAY, cv::COLOR_BGR2GRAY);

	// to HSV color space
	cv::Mat imageHSV;
	cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);

	// to YCrCb color space
	cv::Mat imageYCB;
	cv::cvtColor(image, imageYCB, cv::COLOR_BGR2YCrCb);

	// to LAB color space
	cv::Mat imageLAB;
	cv::cvtColor(image, imageLAB, cv::COLOR_BGR2Lab);

	// Display Matrix(image) in GUI.
	cv::imshow("Original", image);
	cv::imshow("RGB", imageRGB);
	cv::imshow("RGBA", imageRGBA);
	cv::imshow("GRAY", imageGRAY);
	cv::imshow("HSV", imageHSV);
	cv::imshow("YCrCb", imageYCB);
	cv::imshow("LAB", imageLAB);

	// wait with delay for any key from GUI.
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}