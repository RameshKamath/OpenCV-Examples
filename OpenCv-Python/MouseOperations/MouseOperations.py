import numpy as np
import cv2

# Create a black image of 500x300 size
Width = 500
Height = 300

# initialize circle to be drawn
point = (0, 0)
color = (0, 0, 0)

# mouse move location
move_point = (0, 0)
font = cv2.FONT_HERSHEY_SIMPLEX


def mouseClick(event, x, y, flags, params):
    global point, color, move_point
    move_point = (x, y)
    # for left button red
    if event == cv2.EVENT_LBUTTONDOWN:
        point = (x, y)
        color = (0, 0, 255)
    # for right button blue
    elif event == cv2.EVENT_RBUTTONDOWN:
        point = (x, y)
        color = (255, 0, 0)
    # for middle button green
    elif event == cv2.EVENT_MBUTTONDOWN:
        point = (x, y)
        color = (0, 255, 0)


cv2.namedWindow('Draw', cv2.WINDOW_NORMAL)
cv2.setMouseCallback('Draw', mouseClick)
while True:

    Mask = np.zeros((Height, Width, 3), dtype=np.uint8)

    # Draw a red circle on mouse click
    cv2.circle(Mask, center=point, radius=15,
               color=color, thickness=3)

    cv2.putText(Mask, str(move_point), (10, 250), fontFace=font, fontScale=1,
                color=(255, 255, 255), thickness=2, lineType=cv2.LINE_AA)

    cv2.imshow('Draw', Mask)
    # with delay wait till a key is pressed
    if(cv2.waitKey(30) >= 0):
        break

cv2.destroyAllWindows()
