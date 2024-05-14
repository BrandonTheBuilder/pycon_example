#include <Python.h> // everything needed for embedding

PyMODINIT_FUNC PyInit_zipcodes();

int main(int argc, char *argv[]) {
  PyConfig config;
  PyConfig_InitPythonConfig(&config);
  PyConfig_SetBytesArgv(&config, argc, argv);
  PyImport_AppendInittab("zipcodes", PyInit_zipcodes);

  Py_InitializeFromConfig(&config);
  PyConfig_Clear(&config);
  return Py_RunMain();
}
