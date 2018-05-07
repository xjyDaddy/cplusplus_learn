// MonsterGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>
#include <windows.h>
#include <iostream>
#include "City/CityManager.h"
#include "Soldier/SoldierManager.h"
#include "GameConst.h"
#include "GameUtils.h"
#include "GameConfig.h"
time_t nowTime;
time_t lastTime;
time_t interval = 1;
int timeRatio = 100;

void mainLoop();
void init();
void update(time_t dt);
void destroy();
void initGame();

void loadTestData();

int _tmain(int argc, _TCHAR* argv[])
{
	nowTime = time(0);
	lastTime = time(0);
	init();
	mainLoop();
	destroy();
	return 0;
}

void mainLoop()
{
	while (true)
	{
		nowTime = time(0);
		if ( (nowTime - lastTime) >= interval)
		{
			update(nowTime - lastTime);
			lastTime = nowTime;
		}
		else
		{
			Sleep(1);
		}
	}
}

void update(time_t dt)
{
	GameUtils::GetInstance()->addTimeStamp(dt);
	std::cout << "当前时间:" << GameUtils::GetInstance()->getTimeStamp() << std::endl;
	CityManager::GetInstance()->update(dt);
	SoldierManager::GetInstance()->update(dt);
}

void init()
{
	GameUtils::GetInstance()->init();
	GameConfig::GetInstance()->init();
	CityManager::GetInstance()->init();
	SoldierManager::GetInstance()->init();

	initGame();
}

void destroy()
{
	SoldierManager::GetInstance()->destroy();
	CityManager::GetInstance()->destroy();
	GameConfig::GetInstance()->destroy();
	GameConfig::GetInstance()->DestroyInstance();
	GameUtils::GetInstance()->destroy();
	GameUtils::GetInstance()->DestroyInstance();
}

void initGame()
{
	loadTestData();
}

void loadTestData()
{
	GameConfig::GetInstance()->loadArrowAttack(10.0);
	GameConfig::GetInstance()->loadArrowUseTimes(3);
	GameConfig::GetInstance()->loadCityNum(20);
	GameConfig::GetInstance()->loadCityOrigalHp(20.0);
	GameConfig::GetInstance()->loadLionLoyaltyFactor(10.0);
	GameConfig::GetInstance()->loadSwordAbrasionFactor(20.0);
	GameConfig::GetInstance()->loadSwordSoldierFactor (20.0);
	GameConfig::GetInstance()->loadSoldierAttacks({ 5, 5, 5, 5, 5 });
	GameConfig::GetInstance()->loadSoldierHps({ 20, 20, 30, 10, 20 });

	std::vector<CityData> CityDatas = {};
	unsigned int cityNum = GameConfig::GetInstance()->getCityNum(); 
	for (unsigned int i = 0; i < cityNum; i++)
	{
		if (i == 0 || i == cityNum-1)
		{
			Camp camp = i>0 ? BLUE : RED;
			CityManager::GetInstance()->createHeadQuarter(camp, i, cityNum - i);
		}
		else
		{
			CityManager::GetInstance()->createCity(NEUTRALITY, i);
		}
	}
}

