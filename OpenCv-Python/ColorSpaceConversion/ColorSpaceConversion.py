# Created By Ramesh Kamath

import cv2

path = input("Enter path for Image:")

# Read image matrix from Image File
image = cv2.imread(path)

# check if image is read
if image is None:
    print('Image File data not loaded.\nExiting...')
    exit()

# only Important color space conversions are given (Format is same of rest)

# to RGB color space
imageRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

# to RGBA color Space
imageRGBA = cv2.cvtColor(image, cv2.COLOR_BGR2RGBA)

# to Gray color space
imageGRAY = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# to HSV color space
imageHSV = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# to YCrCb color space
imageYCB = cv2.cvtColor(image, cv2.COLOR_BGR2YCrCb)

# to LAB color space
imageLAB = cv2.cvtColor(image, cv2.COLOR_BGR2LAB)


# show Outputs
cv2.imshow('Original', image)
cv2.imshow('RGB', imageRGB)
cv2.imshow('RGBA', imageRGBA)
cv2.imshow('GRAY', imageGRAY)
cv2.imshow('HSV', imageHSV)
cv2.imshow('YCrCb', imageYCB)
cv2.imshow('LAB', imageLAB)

# after delay wait for any key from GUI
cv2.waitKey(0)

# destroy or free any remaining GUI functionality
cv2.destroyAllWindows()
