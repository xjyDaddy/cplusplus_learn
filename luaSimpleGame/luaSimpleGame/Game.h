#pragma once

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int HAPI_GetRandomNumber(lua_State* pLuaState);

int HAPI_BlitBG(lua_State* pLuaState);

int HAPI_BlitSprite(lua_State* pLuaState);

int HAPI_BlitFrame(lua_State* pLuaState);

int HAPI_GetTimerState(lua_State* pLuaState);

void InitLua();

void ShutDownLua();

int ExcuteLuaFile(const char* FuncName);

void CallLuaFunc(const char* FuncName, int iParams, int Result);