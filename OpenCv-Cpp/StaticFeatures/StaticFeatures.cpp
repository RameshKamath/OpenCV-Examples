#include <iostream>
#include <string>
#include <random>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

int vectorMedian(std::vector<int> elements)
{
	std::nth_element(elements.begin(), elements.begin() + elements.size() / 2, elements.end());
	return elements[elements.size() / 2];
}

cv::Mat compute_median(std::vector<cv::Mat> vec)
{
	// mask to store median image
	cv::Mat medianImg(vec[0].rows, vec[0].cols, CV_8UC3, cv::Scalar(0, 0, 0));

	for (int row = 0; row < vec[0].rows; row++)
	{
		for (int col = 0; col < vec[0].cols; col++)
		{
			std::vector<int> elementsBlue;
			std::vector<int> elementsGreen;
			std::vector<int> elementsRed;

			//separate each channel to calculate median seperately
			for (int imgNumber = 0; imgNumber < vec.size(); imgNumber++)
			{
				int Blue = vec[imgNumber].at<cv::Vec3b>(row, col)[0];
				int Green = vec[imgNumber].at<cv::Vec3b>(row, col)[1];
				int Red = vec[imgNumber].at<cv::Vec3b>(row, col)[2];

				elementsBlue.push_back(Blue);
				elementsGreen.push_back(Green);
				elementsRed.push_back(Red);
			}

			medianImg.at<cv::Vec3b>(row, col)[0] = vectorMedian(elementsBlue);
			medianImg.at<cv::Vec3b>(row, col)[1] = vectorMedian(elementsGreen);
			medianImg.at<cv::Vec3b>(row, col)[2] = vectorMedian(elementsRed);
		}
	}
	return medianImg;
}

int main()
{
	std::string path;
	std::cout << "Give Path for Video: ";
	std::cin >> path;

	// open video with path (or) camera with numbers(E.g: 0)
	cv::VideoCapture cap(path);

	// get capture's shape and fps for using in write
	int width = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int height = (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	int fps = (int)cap.get(cv::CAP_PROP_FPS);
	int frameCount = (int)cap.get(cv::CAP_PROP_FRAME_COUNT);

	// make sure video is loading
	if (!cap.isOpened())
	{ // check if video feed is available
		std::cout << "\nvideo capture is not Opened.";
		std::cout << "\nFor Path use \"data/motorway.mp4\" \nExiting...";
		return -1;
	}

	// Randomly select frames
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, frameCount);

	// for storing selected frames
	std::vector<cv::Mat> frames;
	for (int i = 0; i < 25 && cap.isOpened(); i++)
	{
		cv::Mat frame;

		//set frame to position from uniform disribution
		int id = distribution(generator);
		cap.set(cv::CAP_PROP_POS_FRAMES, id);

		// check if frame is available
		if (cap.grab())
		{
			// get frame from capture
			cap.retrieve(frame);
			frames.push_back(frame);
		}
	}

	// Calculate the median for extracting static features
	cv::Mat medianFrame = compute_median(frames);

	// Display Static Features frame
	imshow("Extracted Static Features", medianFrame);
	cv::waitKey(0);

	// Release Resources
	cap.release();
	cv::destroyAllWindows();
	return 0;
}