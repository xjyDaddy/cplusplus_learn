#include "stdafx.h"
#include "GameConfig.h"

GameConfig::GameConfig()
{

}

GameConfig* GameConfig::GetInstance()
{
	if (!s_sharedGameConfig)
	{
		s_sharedGameConfig = new GameConfig();
		s_sharedGameConfig->init();
	}
	return s_sharedGameConfig;
}

void GameConfig::DestroyInstance()
{
	if (s_sharedGameConfig)
	{
		delete s_sharedGameConfig;
	}
	s_sharedGameConfig = nullptr;
}

bool GameConfig::init()
{
	return true;
}

void GameConfig::destroy()
{
	_soldierHp.clear();
	_headQuarterHp.clear();
	_soldierAttack.clear();
}

void GameConfig::loadSoldierHps(const std::vector<float>& soldierHp)
{
	_soldierHp = soldierHp;
}


void GameConfig::loadSoldierAttacks(const std::vector<float>& attacks)
{
	_soldierAttack = attacks;
}


float GameConfig::getSoldierAttack(SoldierType soldierType) const
{
	int index = (int)soldierType;
	return _soldierAttack[index];
}
float GameConfig::getSoldierHp(SoldierType soldierType) const
{
	int index = (int)soldierType;
	return _soldierHp[index];
}

GameConfig* GameConfig::s_sharedGameConfig = nullptr;


