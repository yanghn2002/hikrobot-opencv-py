#include "hikrobot_opencv.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>


namespace py = pybind11;
namespace hik = hikcv;


hik::MvContext::DeviceIndex enum_devices(void) {
    return hik::MvContext::instance().enumDevices();
}


class CvCaptureWrapper {

    hik::CvCapture _camera;
    cv::Mat _image;

    public:
    
        CvCaptureWrapper(const unsigned index)
        : _camera(hik::MvContext::instance().createCapture(index)) { }
        CvCaptureWrapper(const std::string& serial_number)
        : _camera(hik::MvContext::instance().createCapture(serial_number)) { }

        void start(void) {
            _camera.start();
            _image = _camera.ref_cv_mat();
        }

        void stop(void) {
            _camera.stop();
        }

        py::array get(void) {
            _image = _camera.ref_cv_mat();
            int rows = _image.rows;
            int cols = _image.cols;
            int channels = _image.channels();
            int depth = _image.depth();
            py::dtype dtype;
            switch (depth) {
                case CV_8U: dtype = py::dtype::of<uint8_t>();
                    break;
                case CV_8S: dtype = py::dtype::of<int8_t>();
                    break;
                case CV_16U: dtype = py::dtype::of<uint16_t>();
                    break;
                case CV_16S: dtype = py::dtype::of<int16_t>();
                    break;
                case CV_32S: dtype = py::dtype::of<int32_t>();
                    break;
                case CV_32F: dtype = py::dtype::of<float>();
                    break;
                case CV_64F: dtype = py::dtype::of<double>();
                    break;
                default: throw std::runtime_error("Invalid 'cv::Mat' depth");
            }
            std::vector<size_t> shape;
            if (channels == 1)
                shape = { static_cast<size_t>(rows), static_cast<size_t>(cols) };
            else
                shape = { static_cast<size_t>(rows), static_cast<size_t>(cols), static_cast<size_t>(channels) };
            return py::array(dtype, shape, _image.data);
        }

};


PYBIND11_MODULE(hikrobot_opencv_py, module) {

    module.doc() = "Python module for capturing 'python-opencv' image from Hikvision industrial camera.";

    module.def("enum_devices", &enum_devices, py::return_value_policy::copy);

    py::class_<CvCaptureWrapper>(module, "CvCapture")
        .def(py::init<const unsigned>())
        .def(py::init<const std::string&>())
        .def("start", &CvCaptureWrapper::start)
        .def("stop", &CvCaptureWrapper::stop)
        .def("get", &CvCaptureWrapper::get);
    
}