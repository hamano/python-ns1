/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright (C) 2011 Tsukasa Hamano <hamano@osstech.co.jp>
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

