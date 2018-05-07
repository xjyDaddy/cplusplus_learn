#include "stdafx.h"
#include "GameUtils.h"

GameUtils* GameUtils::GetInstance()
{
	if (!s_sharedGameUtils)
	{
		s_sharedGameUtils = new GameUtils();
		s_sharedGameUtils->init();
	}
	return s_sharedGameUtils;
}

void GameUtils::DestroyInstance()
{
	if (s_sharedGameUtils)
	{
		delete s_sharedGameUtils;
	}
	s_sharedGameUtils = nullptr;
}

unsigned long GameUtils::GenCityID()
{
	return ++_headCityID;
}

unsigned long GameUtils::GenSoldierID()
{
	return ++_soldierID;
}

unsigned long GameUtils::GenWeaponID()
{
	return ++_weaponID;
}

bool GameUtils::init()
{
	_headCityID = 0;
	_soldierID = 0;
	_weaponID = 0;
	_timeStamp = 0;
	return true;
}

GameUtils::GameUtils()
{

}

void GameUtils::destroy()
{

}

GameUtils* GameUtils::s_sharedGameUtils = nullptr;


