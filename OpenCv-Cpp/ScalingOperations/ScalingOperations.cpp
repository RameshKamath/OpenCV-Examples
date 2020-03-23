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

	// create empty matrix for storing half size image
	cv::Mat imageHalf;
	//compute to get half size image
	cv::resize(image, imageHalf, cv::Point(0, 0), 0.5, 0.5); // fx =0.5, fy=0.5

	// point variables for hard coded size
	cv::Point size = cv::Point(250, 250);

	// create empty matrix for storing image with hard coded size
	cv::Mat imageHardCode;
	//Hard coded resize
	cv::resize(image, imageHardCode, size);

	// create empty matrix for storing image with interpolated resize
	cv::Mat imageNearest;
	// resize with interpolation(Nearest Neighbor)
	cv::resize(image, imageNearest, size, cv::INTER_NEAREST); // interpolation = cv::INTER_NEAREST

	// Display Matrix(image) in GUI.
	cv::imshow("Original Image", image);
	cv::imshow("Half-Size", imageHalf);
	cv::imshow("Hard-Code", imageHardCode);
	cv::imshow("Interpolation(Nearest Neighbor)", imageNearest);

	// wait with delay for any key from GUI.
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}