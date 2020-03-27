import numpy as np
import cv2

path = input("Enter path for video:")

# open video with path(or) camera with numbers(E.g: 0)
cap = cv2.VideoCapture(path)

# check if file loaded correctly
if (not cap.isOpened()):
    print("\nvideo capture is not Opened. ")
    print('For Path use "data/motorway.mp4" \nExiting...')
    exit()

# get capture's shape and fps for using in write
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = int(cap.get(cv2.CAP_PROP_FPS))
frameCount = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

# Get 25 Frame Ids Randomly
frameIds = frameCount * np.random.uniform(size=25)

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

# Display Static Features frame
cv2.imshow('Extracted Static Features', static)
cv2.waitKey(0)

# destroy or free any remaining GUI functionality
cap.release()
cv2.destroyAllWindows()
