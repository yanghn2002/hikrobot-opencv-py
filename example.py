import hikrobot_opencv_py as hik
import numpy as np
import cv2 as cv


print(hik.enum_devices())

capture = hik.CvCapture(0)
capture.start()

while True:
    image = capture.get()
    width, height = image.shape[:2]
    while width >= 1000 or height >= 1000:
        width /= 2
        height /= 2
    cv.imshow("Hikrobot OpenCV Python example (ESC to exit)", cv.resize(image, (int(height), int(width))))
    if 27 == cv.waitKey(1): break
