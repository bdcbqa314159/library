#include "../cpp/include/cppBook4_bits/nr.hpp"
#include "../cpp/include/cppBook4_bits/test.hpp"
#include "../cpp/include/cppBook4_bits/interp_1d.hpp"
#include "../cpp/include/cppBook4_bits/interp_linear.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void init_message(py::module &m)
{

    m.def("message", &message); //, py::arg("msg"));
}

void init_vectorFloat(py::module &m)
{

    py::class_<vecFlt>(m, "vecFlt32", py::buffer_protocol())
        .def(py::init<size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b)
                      {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<float>::format() || info.ndim != 1)
            	throw std::runtime_error("Incompatible buffer format!");

            auto v = new vecFlt(info.shape[0]);
            memcpy(v->data(), info.ptr, sizeof(float) * v->size());
            return v; }))

        .def("size", &vecFlt::size)

        /// Bare bones interface
        .def("__getitem__",
             [](const vecFlt &m, size_t i)
             {
                 if (i < 0 || i >= m.size())
                     throw py::index_error();
                 return m[i];
             })

        .def("__setitem__",
             [](vecFlt &m, size_t i, float v)
             {
                 if (i < 0 || i >= m.size())
                     throw py::index_error();
                 return m[i] = v;
             })
        /// Provide buffer access
        .def_buffer([](vecFlt &m) -> py::buffer_info
                    { return py::buffer_info(
                          m.data(),                               /* Pointer to buffer */
                          sizeof(float),                          /* Size of one scalar */
                          py::format_descriptor<float>::format(), /* Python struct-style format descriptor */
                          1,                                      /* Number of dimensions */
                          {m.size()},                             /* Buffer dimensions */
                          {sizeof(float) * m.size()}); });
}

void init_vectorDouble(py::module &m)
{

    py::class_<vecDoub>(m, "vecFlt64", py::buffer_protocol())
        .def(py::init<size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b)
                      {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<double>::format() || info.ndim != 1)
            	throw std::runtime_error("Incompatible buffer format!");

            auto v = new vecDoub(info.shape[0]);
            memcpy(v->data(), info.ptr, sizeof(double) * v->size());
            return v; }))

        .def("size", &vecDoub::size)

        /// Bare bones interface
        .def("__getitem__",
             [](const vecDoub &m, size_t i)
             {
                 if (i < 0 || i >= m.size())
                     throw py::index_error();
                 return m[i];
             })

        .def("__setitem__",
             [](vecDoub &m, size_t i, float v)
             {
                 if (i < 0 || i >= m.size())
                     throw py::index_error();
                 return m[i] = v;
             })
        /// Provide buffer access
        .def_buffer([](vecDoub &m) -> py::buffer_info
                    { return py::buffer_info(
                          m.data(),                                /* Pointer to buffer */
                          sizeof(double),                          /* Size of one scalar */
                          py::format_descriptor<double>::format(), /* Python struct-style format descriptor */
                          1,                                       /* Number of dimensions */
                          {m.size()},                              /* Buffer dimensions */
                          {sizeof(double) * m.size()}); });
}

void init_interp_linear(py::module &m)
{
    py::class_<Linear_interp>(m, "Linear_interp")
        .def(py::init<vecDoub_I &, vecDoub_I &>())
        .def("rawinterp", &Linear_interp::rawinterp)
        .def("interp", &Linear_interp::interp);
}

void init_poly_interp(py::module &m)
{
    py::class_<Poly_interp>(m, "Poly_interp")
        .def(py::init<vecDoub_I &, vecDoub_I &, int>())
        .def("rawinterp", &Poly_interp::rawinterp)
        .def("interp", &Poly_interp::interp);
}