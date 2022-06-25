#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_message(py::module &);
void init_vectorFloat(py::module &m);
void init_vectorDouble(py::module &m);

void init_interp_linear(py::module &m);
void init_poly_interp(py::module &m);

namespace myNumpy
{

    PYBIND11_MODULE(myNumpy, m)
    {
        // Optional docstring
        m.doc() = "Working with the famous Numerical Recipes 3rd Edition and trying to humbly build my version of numpy python library.";

        init_message(m);

        init_vectorFloat(m);
        init_vectorDouble(m);

        init_interp_linear(m);
        init_poly_interp(m);
    }

}
