// simpleLua.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
extern "C"
{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

#define PopLuaInt(pLuaState, iDest) \
{\
	iDest = (int)lua_tonumber(pLuaState, lua_gettop(pLuaState)); \
	lua_pop(pLuaState, 1);\
}

int PrintString(lua_State* pLuaState)
{
	int iStringCount = lua_gettop(pLuaState);
	for (int iCurrStringIndex = 1; iCurrStringIndex <= iStringCount; iCurrStringIndex++)
	{
		if (!lua_isstring(pLuaState , 1))
		{
			//lua_error(pLuaState, "Invalid String.");
			printf("Invalid String.");
		}
		else
		{
			printf("\t");
			printf(lua_tostring(pLuaState, iCurrStringIndex));
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	lua_State* pLuaState = lua_open();
	luaL_openlibs(pLuaState);

	lua_register(pLuaState, "PrintString", PrintString);

	int iErrorCode = luaL_dofile(pLuaState, "D://Documents//Desktop//headShoot//simpleLua//simpleLua//Debug//test.lua");

	lua_getglobal(pLuaState, "AddTwo");

	lua_pushnumber(pLuaState, 4);
	lua_pushnumber(pLuaState, 5);

	lua_call(pLuaState, 2, 1);
	int result = (int)lua_tonumber(pLuaState, 1);
	cout << "result: " << result << endl;
	lua_pop(pLuaState, 1);


	//读取全局变量
	lua_getglobal(pLuaState, "GlobalVar");
	int GlobalVar = (int)lua_tonumber(pLuaState, 1);
	lua_pop(pLuaState, 1);
	cout << "GlobalVar :" << GlobalVar << endl;

	lua_pushnumber(pLuaState, 3.1415926);
	lua_setglobal(pLuaState, "GlobalVar");
	lua_getglobal(pLuaState, "GlobalVar");
	auto GlobalVarFloat = lua_tonumber(pLuaState, 1);
	lua_pop(pLuaState, 1);
	cout << "GlobalVar :" << GlobalVarFloat << endl;

	lua_pushnumber(pLuaState, 3.1415926);
	int t = 0;
	PopLuaInt(pLuaState, t);
	cout << "t: " << t << endl;
	if (iErrorCode == 0)
	{
		cout << "\n执行成功" << endl;
	}
	else
	{   
		cout << "\n执行失败： " <<  iErrorCode << endl;
	}
	lua_close(pLuaState);
	while (true)
	{
	}
	return 0;
}

