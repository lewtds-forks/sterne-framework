#include <python3.2/Python.h>
 
int main() {
    Py_Initialize();
    PyObject *pName, *pModule, *pFunc;
    PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyUnicode_FromString("./framework"));
    pName = PyUnicode_FromString("framework");
    pModule = PyImport_Import(pName);
    if(!pModule) {
        PyErr_Print();
        return 0;
    }
    Py_DECREF(pName);
    pFunc = PyObject_GetAttrString(pModule, "sterne_start");
    PyObject_CallObject(pFunc, NULL);
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
    Py_Finalize();
    return 0;
}
