// luaSimpleGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
extern "C"
{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#include "Game.h"
#include <time.h>
#include <windows.h>
#include <iostream>
time_t nowTime;
time_t lastTime;
time_t interval = 1;

void mainLoop()
{
	while (true)
	{
		nowTime = time(0);
		if (nowTime - lastTime > interval)
		{
			CallLuaFunc("updateFrame", 0, 0);
			lastTime = nowTime;
		}
		else
		{
			Sleep(1);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	InitLua();

	if (ExcuteLuaFile("test.lua") != 0)
	{
		std::cout << "脚本执行失败" << std::endl;
		return -1;
	}

	lastTime = time(0);
	CallLuaFunc("init", 0, 0);
	mainLoop();
	ShutDownLua();

	return 0;
}

