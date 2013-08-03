#include <SFML/Graphics.hpp>
#include <python3.2/Python.h>
 
namespace yami {
    int w_width = 800 ;
    int w_height = 450 ;
    int fps = 60 ;
    float max_skip = 0.2f;
    std::string title = "Yami Test";
    sf::VideoMode vm(yami::w_width, yami::w_height, 32);
    sf::RenderWindow wd;
}
 
static PyObject *start_sterne(PyObject *self, PyObject *args) {
    using namespace yami;
    wd.create(vm, yami::title);
    Py_RETURN_NONE;
}
 
static PyObject *update_sterne(PyObject *self, PyObject *args) {
    using namespace yami;
    sf::Event event;
    while (wd.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            wd.close();
            exit(0);
        }
    }
    wd.display();
    Py_RETURN_NONE;
}
 
static PyMethodDef SterneMethods[] = {
    {"start_sterne", start_sterne, METH_VARARGS, "Create."},
    {"update_sterne", update_sterne, METH_VARARGS, "Update."},
    {NULL, NULL, 0, NULL}
};
 
static struct PyModuleDef SterneModule = {
    PyModuleDef_HEAD_INIT, "sterne", NULL, -1, SterneMethods
};
 
PyMODINIT_FUNC
PyInit_sterne(void)
{
    return PyModule_Create(&SterneModule);
}
