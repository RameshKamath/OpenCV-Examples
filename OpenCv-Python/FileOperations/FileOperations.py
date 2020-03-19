#! python
import cv2

path = input("Enter path for Image:")

# Read image from path File
image = cv2.imread(path)

# check if image is loaded
if image is None:
    print('Image File data not loaded.\nExiting...')
    exit()

# Resize the image with width, height
width = 512
height = 512
resized = cv2.resize(image, (width, height))

# Write the image to file
cv2.imwrite("output/resizedOnOpencv.jpg", resized)

# show the image in a GUI
cv2.imshow('original', image)
cv2.imshow('resized', resized)

# after delay wait for any key from GUI
cv2.waitKey(0)

# destroy or free any remaining GUI functionality
cv2.destroyAllWindows()
