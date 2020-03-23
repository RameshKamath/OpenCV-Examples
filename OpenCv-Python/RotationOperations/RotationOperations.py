import cv2

path = input("Enter path for Image:")

# Read image matrix from Image File
image = cv2.imread(path)

# check if image is read
if image is None:
    print('Image File data not loaded.\nExiting...')
    exit()

# Angle in degres
Angle = 45

# Image center
center = (image.shape[1]/2, image.shape[0]/2)

# get Rotation Matrix
RMatrix = cv2.getRotationMatrix2D(
    center=center, angle=Angle, scale=1)

# Rotate with affine transform
Rotated_Image = cv2.warpAffine(src=image, M=RMatrix,
                               dsize=(image.shape[1], image.shape[0]))

# show the images in a GUI
cv2.imshow('original', image)
cv2.imshow('Rotated Image', Rotated_Image)

# after delay wait for any key from GUI
cv2.waitKey(0)

# destroy or free any remaining GUI functionality
cv2.destroyAllWindows()
