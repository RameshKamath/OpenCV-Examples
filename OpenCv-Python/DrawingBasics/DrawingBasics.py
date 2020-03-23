# Created By Ramesh Kamath

# import numpy for mask
import numpy as np
import cv2

# Create a black image
Width = 500
Height = 300
lineMask = np.zeros((Height, Width, 3), dtype=np.uint8)
rectMask = np.zeros((Height, Width, 3), dtype=np.uint8)
polyMask = np.zeros((Height, Width, 3), dtype=np.uint8)
circleMask = np.zeros((Height, Width, 3), dtype=np.uint8)
textMask = np.zeros((Height, Width, 3), dtype=np.uint8)
ellipseMask = np.zeros((Height, Width, 3), dtype=np.uint8)

# Draw a diagonal blue line
cv2.line(lineMask, pt1=(0, 0), pt2=(200, 200), color=(255, 0, 0), thickness=5)

# Draw a green rectangle
cv2.rectangle(rectMask, pt1=(10, 10), pt2=(200, 200),
              color=(0, 255, 0), thickness=5)

# Draw a red circle
cv2.circle(circleMask, center=(100, 100), radius=50,
           color=(0, 0, 255), thickness=-5)

# Draw an inclined ellipse
cv2.ellipse(ellipseMask, center=(100, 100), axes=(100, 50), angle=20,
            startAngle=0, endAngle=180, color=255, thickness=5)

# Draw a closed polygon defined by a set of points
pts = np.array([[10, 5], [20, 30], [70, 20], [50, 10]], dtype=np.int32)
pts = pts.reshape((-1, 1, 2))
cv2.polylines(polyMask, [pts], isClosed=True, color=(0, 255, 255))

# Finally draw some text with anti-aliased font
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(textMask, 'OpenCV', (10, 250), fontFace=font, fontScale=2,
            color=(255, 255, 255), thickness=2, lineType=cv2.LINE_AA)

# Display the image
cv2.imshow('Line', lineMask)
cv2.imshow('Rectangle', rectMask)
cv2.imshow('circle', circleMask)
cv2.imshow('ellipse', ellipseMask)
cv2.imshow('Polyline', polyMask)
cv2.imshow('text', textMask)


# with delay wait till a key is pressed
cv2.waitKey(0)
cv2.destroyAllWindows()
