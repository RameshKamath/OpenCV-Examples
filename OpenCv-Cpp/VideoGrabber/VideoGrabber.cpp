// Created By Ramesh Kamath
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

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

	// Output video File Name
	const std::string Filename = "VideoGrabber_output.avi";

	// Shape to write
	cv::Size shape = cv::Size(width, height);

	// Create VideoWriter object and fourcc codec
	int fourcc = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
	cv::VideoWriter out = cv::VideoWriter::VideoWriter(Filename, fourcc, fps, shape);

	// make sure video is loading
	if (!cap.isOpened())
	{ // check if video feed is available
		std::cout << "\nvideo capture is not Opened.\nExiting...";
		return -1;
	}

	cv::namedWindow("Video out");

	while (cap.isOpened())
	{
		cv::Mat frame;

		// check if frame is available
		if (cap.grab())
		{

			// get frame from capture
			cap.retrieve(frame);

			// Display frame in named GUI for video.
			cv::imshow("Video out", frame);

			// write frame to file
			out.write(frame);

			// wait with delay for any key from GUI to exit loop.
			if ((char)cv::waitKey(30) >= 0)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	// Release Resources
	cap.release();
	out.release();
	cv::destroyAllWindows();
	return 0;
}