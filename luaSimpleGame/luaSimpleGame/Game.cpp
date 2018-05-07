#include "stdafx.h"
#include "Game.h"
#include <random>
#include <string.h>

lua_State* g_pLuaState;

#define GetIntParam(Index) \
	(int)lua_tonumber(g_pLuaState, Index);

#define ReturnNumber(Num) \
	lua_pushnumber(g_pLuaState, Num);

int HAPI_GetRandomNumber(lua_State* pLuaState)
{
	int iMin = GetIntParam(1);
	int iMax = GetIntParam(2);
	
	ReturnNumber((rand() % (iMax + 1 - iMin)) + iMin);
	return 1;
}

int HAPI_BlitSprite(lua_State* pLuaState)
{
	//read params
	int iIndex = GetIntParam(1);
	int iX = GetIntParam(2);
	int iY = GetIntParam(2);
	//show sprite
	return 0;
}

void InitLua()
{
	g_pLuaState = lua_open();
	luaL_openlibs(g_pLuaState);
	lua_register(g_pLuaState, "GetRandomNumber", HAPI_GetRandomNumber);
	luaL_dofile(g_pLuaState, "D://Documents//Desktop//headShoot//luaSimpleGame//Debug//test.lua");
}

void ShutDownLua()
{
	lua_close(g_pLuaState);
}

void CallLuaFunc(const char* FuncName, int iParams, int Result)
{
	lua_getglobal(g_pLuaState, FuncName);
	lua_call(g_pLuaState, iParams, Result);
}              

int ExcuteLuaFile(const char* FuncName)
{
	std::string filePath = "D://Documents//Desktop//headShoot//luaSimpleGame//Debug//";
	filePath.append(FuncName);
	return luaL_dofile(g_pLuaState, filePath.c_str());
}