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
	// Load Image from path to a Matrix
	cv::Mat image;
	image = cv::imread(path);

	// make sure data is loaded
	if (!image.data)
	{
		std::cout << "\nImage File data not loaded.\nExiting...";
		return -1;
	}

	// create empty matrix for storing resized image
	cv::Mat resized;

	// create point with two variables for size
	cv::Point size = cv::Point(512, 512);
	cv::resize(image, resized, size);

	// Write Image matrix to Image file
	cv::imwrite("resizedOnOpencv.jpg", resized);

	// Display Images in GUI.
	cv::imshow("image", image);
	cv::imshow("imageResized", resized);

	// wait with delay for any key from GUI.
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}