#include <Python.h>
#include "santa.h"

static PyObject* distance(PyObject* self, PyObject* args)
{
    PyObject *pathlist;

    if (!PyArg_ParseTuple(args, "O", &pathlist))
        return NULL;
	int len = PyObject_Length(pathlist);
	unsigned int path[len];
	
	for (int i=0; i<len; i++) {
		PyLongObject *item = PyList_GetItem(pathlist, i);
		path[i] = (unsigned int) PyLong_AsLong(item);
	}

	double totaldist = totaldistance(path, len);
	
    return Py_BuildValue("f", totaldist);
}

static PyMethodDef SantaMethods[] =
{
     {"distance", distance, METH_VARARGS, "Returns the total distance covered by a given path."},
     {NULL, NULL, 0, NULL}
};

static struct PyModuleDef Santa_Module = {  
    PyModuleDef_HEAD_INIT,
    "santa",     // name of module exposed to Python
    "Wrapper for the santa library.", // module documentation
    -1,
    SantaMethods
};

PyMODINIT_FUNC PyInit_santa(void)
{
     return PyModule_Create(&Santa_Module);
}
