// cplusplus_name_mangling.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const char* mangling_name = "_ZN9wikipedia7article6formatB5cxx11Ev";
	char *demangle_name = (char*)malloc(30);
	int status = 0;
	size_t len = 30;

	//内网没有abi库 。。。
	demangle_name = abi::__cxa_

}

