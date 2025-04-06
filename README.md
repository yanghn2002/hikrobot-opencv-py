# Hikrobot OpenCV Python

Python module for capturing 'python-opencv' image from Hikvision industrial camera, Python binding for the ['hikrobot-opencv-cpp'](https://github.com/yanghn2002/hikrobot-opencv-cpp) project.

```shell
git clone https://github.com/yanghn2002/hikrobot-opencv-cpp
```

## Usage

[Hikrobot-OpenCV-CPP requirements here](hikrobot-opencv-cpp/doc/requirements.md) ([*Github*](https://github.com/yanghn2002/hikrobot-opencv-cpp/blob/main/doc/requirements.md))

```shell
pip install numpy opencv-python
```

### Build module

```shell
pip install pybind11
make
```

### Import module

```python
import hikrobot_opencv_py as hik
```