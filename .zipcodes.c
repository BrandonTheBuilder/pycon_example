#include "Python.h"
#include "zipcode_data.h"

PyObject *py_load_file(PyObject *self, PyObject *arg) {
  const char *name = PyUnicode_AsUTF8(arg);
  load_file(name);
  return Py_None;
}

PyObject *py_count_orders(PyObject *self, PyObject *arg) {
  int zipcode = PyLong_AsLong(arg);
  int result = count_orders(zipcode);
  return PyLong_FromLong(result);
}

static PyMethodDef methods[] = {
    {"load_file", py_load_file, METH_O, "Loads a data file"},
    {"count_orders", py_count_orders, METH_O,
     "Counts occurence of zipcode in data"},
    {NULL, NULL, 0, NULL}};

static PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "zipcodes",     .m_size = 0,
    .m_methods = methods,  .m_free = NULL,
};

PyMODINIT_FUNC PyInit_zipcodes() { return PyModuleDef_Init(&module); }
