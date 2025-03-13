import hikrobot_opencv_py as hikcv
import numpy as np
import cv2 as cv


print(hikcv.enum_devices())

capture = hikcv.CvCapture(0)
capture.start()

while True:
    image = capture.get()
    width, height = image.shape[:2]
    while width >= 1000 or height >= 1000:
        width /= 2
        height /= 2
    cv.imshow("Hikrobot OpenCV Python example (ESC to exit)", cv.resize(image, (int(height), int(width))))
    if 27 == cv.waitKey(1): break
