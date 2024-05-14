#include <Python.h> // everything needed for embedding

int main(int argc, char *argv[]) {
  PyConfig config;
  PyConfig_InitPythonConfig(&config);
  PyConfig_SetBytesArgv(&config, argc, argv);

  Py_InitializeFromConfig(&config);
  PyConfig_Clear(&config);
  return Py_RunMain();
}
