# Created By Ramesh Kamath

import cv2

path = input("Enter path for video:")

# open video with path(or) camera with numbers(E.g: 0)
cap = cv2.VideoCapture(path)

# get capture's shape and fps for using in write
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = int(cap.get(cv2.CAP_PROP_FPS))

# Create VideoWriter object and fourcc codec
fourcc = cv2.VideoWriter_fourcc('M', 'J', 'P', 'G')
out = cv2.VideoWriter("output/VideoGrabber_output.avi",
                      fourcc, fps, (width, height))

# check if file loaded correctly
if (not cap.isOpened()):
    print("\nvideo capture is not Opened.\nExiting...")
    exit()

cv2.namedWindow("Video out")

while(cap.isOpened()):
    # get frame from capture
    ret, frame = cap.read()
    if ret is True:
        # show the frame in a GUI for video
        cv2.imshow("Video out", frame)

        # write frame to file
        out.write(frame)
        # after delay wait for any key from GUI
        if (cv2.waitKey(30) >= 0):
            break
    else:
        break

# destroy or free any remaining GUI functionality
cap.release()
out.release()
cv2.destroyAllWindows()
