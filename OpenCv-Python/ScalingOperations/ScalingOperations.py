import cv2

path = input("Enter path for Image:")

# Read image matrix from Image File
image = cv2.imread(path)

# check if image is read
if image is None:
    print('Image File data not loaded.\nExiting...')
    exit()

# compute to get half size image
image_half = cv2.resize(image, (0, 0), fx=0.5, fy=0.5)

# Hard coded resize
image_hardCode = cv2.resize(image, (250, 250))

# resize with interpolation (Nearest Neighbor)
image_nearest = cv2.resize(image, (250, 250), interpolation=cv2.INTER_NEAREST)

# show the images in a GUI
cv2.imshow('original', image)
cv2.imshow('Half-Size', image_half)
cv2.imshow('Hard-Code', image_hardCode)
cv2.imshow('Interpolation(Nearest Neighbor)', image_nearest)

# after delay wait for any key from GUI
cv2.waitKey(0)

# destroy or free any remaining GUI functionality
cv2.destroyAllWindows()
