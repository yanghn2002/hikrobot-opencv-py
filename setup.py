import subprocess
from setuptools import setup
from setuptools.command.build import build


class Build(build):
    def run(self):
        subprocess.check_call(['make', 'build'])
        super().run()

setup(
    name="hikrobot-opencv",
    version="0.1.0",
    packages=['hikrobot_opencv'],
    package_data={'hikrobot_opencv': ['hikrobot_opencv_py.*.so']},
    include_package_data=True,
    cmdclass={'build': Build},
    install_requires=[
        "pybind11",
        "numpy",
        "opencv-python",
    ],
    author="yanghn2002",
)