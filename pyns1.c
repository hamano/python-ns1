#include <Python.h>

static char pyns1_doc[] = "NS1 Hash for Python\n";

static PyObject * pyns1_evalue(PyObject *self, PyObject *args)
{
    PyObject *ret;
    const char *plain;
    char *crypt;
    if(!PyArg_ParseTuple(args, "s", &plain)){
        return NULL;
    }
    crypt = evalue(plain);
    ret = PyString_FromString(crypt);
    free(crypt);
    return ret;
}

static PyObject * pyns1_dvalue(PyObject *self, PyObject *args)
{
    PyObject *ret;
    const char *crypt;
    char *plain;
    if(!PyArg_ParseTuple(args, "s", &crypt)){
        return NULL;
    }
    plain = dvalue(crypt);
    ret = PyString_FromString(plain);
    free(plain);
    return ret;
}

static PyMethodDef methods[] = {
	{"hash", pyns1_evalue, METH_VARARGS, "ns1 hash.\n"},
	{"evalue", pyns1_evalue, METH_VARARGS, "ns1 evalue.\n"},
	{"dvalue", pyns1_dvalue, METH_VARARGS, "ns1 dvalue.\n"},
	{NULL, NULL}
};

void initns1(void)
{
	Py_InitModule3("ns1", methods, pyns1_doc);
}

