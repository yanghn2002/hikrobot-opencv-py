import hikrobot_opencv as hik
import cv2 as cv


print(f"Hikrobot OpenCV {hik.__version__}")

devices = hik.enum_devices()
print("devices:")
for index in devices:
    print(f"\t{index}: {devices[index]}")

input_serial_number = input("input camera serial number to open: ")

capture = hik.CvCapture(input_serial_number)
capture.start()

while True:
    image = capture.get()
    width, height = image.shape[:2]
    while width >= 1000 or height >= 1000:
        width /= 2
        height /= 2
    cv.imshow("Hikrobot OpenCV Python example (ESC to exit)", cv.resize(image, (int(height), int(width))))
    if 27 == cv.waitKey(1): break
