# Hikrobot OpenCV Python

Python module for capturing 'python-opencv' image from Hikvision industrial camera, Python binding for the ['hikrobot-opencv-cpp'](https://github.com/yanghn2002/hikrobot-opencv-cpp) project.

## Build & Install

[Hikrobot-OpenCV-CPP requirements](https://github.com/yanghn2002/hikrobot-opencv-cpp/blob/main/doc/requirements.md)

```shell
pip install git+https://github.com/yanghn2002/hikrobot-opencv-py
```

> or
> 
> ```shell
> git clone https://github.com/yanghn2002/hikrobot-opencv-py
> cd hikrobot-opencv-py
> git clone https://github.com/yanghn2002/hikrobot-opencv-cpp
> pip install -r requirements.txt
> pip install .
> ```

## Usage

```shell
python3 -m hikrobot_opencv
```

```python
import hikrobot_opencv as hik
```