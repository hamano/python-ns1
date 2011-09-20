/*
 * Copyright (c) 2011, Open Source Solution Technology Corporation,
 * Tsukasa Hamano <hamano@osstech.co.jp>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <Python.h>
#include "ns_crypt.h"

static char pyns1_doc[] = "Sun's NS1 Hash Function for Python\n";

static PyObject * pyns1_evalue(PyObject *self, PyObject *args)
{
    PyObject *ret;
    char *plain;
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
    char *crypt;
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

