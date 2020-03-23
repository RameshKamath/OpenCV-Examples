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

	//Angle in degres
	double Angle = 45;

	//Image center
	cv::Point2f center = cv::Point(image.cols / 2, image.rows / 2);

	// Rotation Matrix
	cv::Mat rMatrix;

	//get Rotation Matrix
	rMatrix = cv::getRotationMatrix2D(center, Angle, 1);

	//Rotate with affine transform
	cv::Mat rotatedImage;
	cv::Size size = cv::Point(image.cols, image.rows);
	cv::warpAffine(image, rotatedImage, rMatrix, size);

	// Display Matrix(image) in GUI.
	cv::imshow("Original Image", image);
	cv::imshow("Rotated Image", rotatedImage);

	// wait with delay for any key from GUI.
	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}