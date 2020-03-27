import numpy as np
import cv2

path = input("Enter path for video:")

# open video with path(or) camera with numbers(E.g: 0)
cap = cv2.VideoCapture(path)

# check if file loaded correctly
if (not cap.isOpened()):
    print("\n video capture is not Opened. ")
    print('For Path use "data/motorway.mp4" \nExiting...')
    exit()

# get capture's shape and fps for using in write
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = int(cap.get(cv2.CAP_PROP_FPS))

# Get 30 Frame Ids Randomly
frameIds = cap.get(cv2.CAP_PROP_FRAME_COUNT) * np.random.uniform(size=30)

frames = []
# get the frames and store them in array
for id in frameIds:
    # set frame to position
    cap.set(cv2.CAP_PROP_POS_FRAMES, id)
    ret, frame = cap.read()
    if ret:
        frames.append(frame)

# Calculate the median along the time axis for extracting Static Features
static = np.median(frames, axis=0).astype(dtype=np.uint8)

# Reset frame number to 0 to go back to begining
cap.set(cv2.CAP_PROP_POS_FRAMES, 0)

# convert to gray for comparison
grayStatic = cv2.cvtColor(static, cv2.COLOR_BGR2GRAY)

cv2.namedWindow('Extracted Dynamic Features', cv2.WINDOW_NORMAL)

while(cap.isOpened()):
    ret, frame = cap.read()

    if ret is True:

        # convert to gray for comparison
        grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Calculate difference between current frame and median frame
        Difference = cv2.absdiff(grayFrame, grayStatic)
        # Treshold to remove noise
        th, Difference = cv2.threshold(Difference, 30, 255, cv2.THRESH_BINARY)
        # Display Dynamic Features frame
        cv2.imshow('Extracted Dynamic Features', Difference)

        # after delay wait for any key from GUI
        if (cv2.waitKey(30) >= 0):
            break
    else:
        break

# destroy or free any remaining GUI functionality
cap.release()
cv2.destroyAllWindows()
