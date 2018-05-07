#include "../stdafx.h"
#include "SoldierManager.h"
#include "IceMan.h"
#include "Ninjia.h"
#include "Wolf.h"
#include "Dragon.h"
#include "Lion.h"
#include "../GameUtils.h"
SoldierManager* SoldierManager::GetInstance()
{
	if (!s_sharedSoldierManager)
	{
		s_sharedSoldierManager = new SoldierManager();
		s_sharedSoldierManager->init();
	}
	return s_sharedSoldierManager;
}

void SoldierManager::DestroyInstace()
{
	if (s_sharedSoldierManager)
	{
		delete s_sharedSoldierManager;
	}
	s_sharedSoldierManager = nullptr;
}

SoldierManager::SoldierManager()
{
	
}

Soldier* SoldierManager::CreateSoldierByType(SoldierType soldierType ,HeadQuarter* parent, unsigned int createNumber)
{
	Soldier* newSoldier;
	switch (soldierType)
	{
	case ICE_MAN:
		newSoldier = new IceMan(soldierType, parent, createNumber);
		break;
	case DRAGON:
		newSoldier = new Dragon(soldierType, parent, createNumber);
		break;
	case NINJA:
		newSoldier = new Ninjia(soldierType, parent, createNumber);
		break;
	case WOLF:
		newSoldier = new Wolf(soldierType, parent, createNumber);
		break;
	case LION:
		newSoldier = new Lion(soldierType, parent, createNumber);
		break;
	default:
		newSoldier = nullptr;
		break;
	}
	if (newSoldier)
	{
		_soldiers.emplace_back(newSoldier);
	}
	return newSoldier;
}

void SoldierManager::init()
{

}

void SoldierManager::CleanSoldiers()
{
	for (auto& soldier : _soldiers)
	{
		delete soldier;
	}
}

void SoldierManager::update(time_t dt)
{
	for (auto soldier : _soldiers)
	{
		soldier->update(dt);
	}

	if (GameUtils::GetInstance()->getTimeStampPerHour() == 59)
	{
		//删除那些逃跑和阵亡的士兵
		for (auto iter = _soldiers.begin(); iter != _soldiers.end(); iter++)
		{
			SoldierStatus status = (*iter)->getStatus();
			if (status == RUN_AWAY || status == DEAD)
			{
				delete (*iter);
				iter = _soldiers.erase(iter);
			}
		}
	}
}

void SoldierManager::destroy()
{
	CleanSoldiers();
}

std::vector<Soldier*> SoldierManager::getAliveSoliderByCityID(unsigned int cityID) const
{
	std::vector<Soldier*> targetSoldiers;
	for (auto &soldier : _soldiers)
	{
		if (soldier->getCurrentCityID() == cityID && soldier->getStatus() == ALIVE)
		{
			targetSoldiers.emplace_back(soldier);
		}
	}
	return targetSoldiers;
}

std::vector<Soldier*> SoldierManager::getAliveSoliderByCityID(unsigned int cityID, Camp camp) const
{
	std::vector<Soldier*> targetSoldiers;
	for (auto &soldier : _soldiers)
	{
		if (soldier->getCurrentCityID() == cityID && soldier->getStatus() == ALIVE && camp == soldier->getCamp())
		{
			targetSoldiers.emplace_back(soldier);
		}
	}
	return targetSoldiers;
}

SoldierManager* SoldierManager::s_sharedSoldierManager = nullptr;
