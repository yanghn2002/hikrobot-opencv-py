CXX = g++

OUTPUT = hikrobot_opencv_py$(shell python3-config --extension-suffix)

PYBIND11_FLAGS = $(shell python3 -m pybind11 --includes)


include hikrobot-opencv-cpp/hikrobot_opencv.mk

FLAGS = $(PYBIND11_FLAGS) $(HIKCV_CV_FLAGS) $(HIKCV_MV_FLAGS) -Ihikrobot-opencv-cpp


build: hikrobot_opencv_py.cpp
	g++ hikrobot_opencv_py.cpp $(FLAGS) -O3 -Wall -shared -fPIC -o $(OUTPUT) 