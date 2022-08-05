#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "kdtrace/kdtrace.hpp"

namespace py = pybind11;

namespace kdtrace {

PYBIND11_MODULE(_kdtrace, m)
{
  m.doc() = "Python Bindings for KDTrace";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace kdtrace
