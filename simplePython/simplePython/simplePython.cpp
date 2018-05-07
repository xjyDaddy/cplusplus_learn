// simplePython.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Python.h>
#include <iostream>

//C++调用python函数
void test_CallPythonMethod(PyObject* pModule);

void init_HostApi();

PyObject* RepeatString(PyObject* pSelf, PyObject* pParams);


PyMethodDef HostAPIFuncs[] = {
	{ "RepeatString", RepeatString, METH_VARARGS ,  NULL},
	{ NULL, NULL, NULL, NULL}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();
	init_HostApi();
	PyObject* pName = PyString_FromString("test_0");
	PyObject* pModule = PyImport_Import(pName);
	do 
	{
		if (!pModule)
		{
			printf("could not open script.\n");
			break;
		}
		printf("open script success.\n");
		
		test_CallPythonMethod(pModule);

	} while (0);
	Py_Finalize();
	while (true)
	{

	}
	return 0;
}

void test_CallPythonMethod(PyObject* pModule)
{
	PyObject* pDict = PyModule_GetDict(pModule);
	PyObject* pFunc = PyDict_GetItemString(pDict, "GetMax");
	//参数传递
	PyObject* pParams = PyTuple_New(2);
	PyObject* pCurrParam;
	pCurrParam = PyInt_FromLong(16);
	PyTuple_SetItem(pParams, 0, pCurrParam);
	pCurrParam = PyInt_FromLong(32);
	PyTuple_SetItem(pParams, 1, pCurrParam);
	PyObject* pMax = PyObject_CallObject(pFunc, pParams);
	int iMax = PyInt_AsLong(pMax);

	std::cout << "c++ call python method getMax(16,32): " << iMax << std::endl;
}


PyObject* RepeatString(PyObject* pSelf, PyObject* pParams)
{
	char * pstrString;
	int iRepCount;
	if (!PyArg_ParseTuple(pParams , "si" , &pstrString , &iRepCount)) 
	{
		printf("unable to parse parameter tuple.\n");
		exit(0);
	}

	for (int iCurrStringRep = 0; iCurrStringRep < iRepCount; ++iCurrStringRep)
	{
		printf("\t\t%d: %s\n", iCurrStringRep, pstrString);
	}
	return PyInt_FromLong(iRepCount);
}

void init_HostApi()
{
	if (!PyImport_AddModule("HostAPI"))
	{
		printf("Host API module could not be created.");
	}
	if (!Py_InitModule("HostAPI", HostAPIFuncs))
	{
		printf("Host API module could not be initialized.");
	}
}