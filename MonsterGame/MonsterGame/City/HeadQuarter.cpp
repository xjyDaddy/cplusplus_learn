#include "../stdafx.h"
#include <algorithm>
#include <iostream>
#include "HeadQuarter.h"
#include "../GameConfig.h"
#include "../Soldier/SoldierManager.h"
#include "../GameUtils.h"

HeadQuarter::HeadQuarter(Camp camp, unsigned int cityID, unsigned int targetCityID) :City(camp ,cityID)
{
	_createSoldierCursor = 0;
	_createNum = 0;
	_soliderBook = camp == RED ? 0 : 1;
}

HeadQuarter::~HeadQuarter()
{

}

Soldier* HeadQuarter::tryAddSoldier()
{
	bool createFlag = checkCanCreateMinHpSoldier();
	if (!createFlag) return false;
	bool isCreateSuccess = false;
	Soldier* newSoldier = nullptr;
	do
	{
		SoldierType soldierType = getSoldierTypeInBook(_createSoldierCursor);
		float soldierHp = GameConfig::GetInstance()->getSoldierHp(soldierType);
		if (soldierHp <= _currentHp)
		{
			newSoldier = addSoldier(soldierType);
			if (!newSoldier) return nullptr;
		}
		addSoldierCursor();
	} while (!newSoldier);
	return newSoldier;
}

bool HeadQuarter::checkHpEnoughBySoldierType() const
{
	float needHp = GameConfig::GetInstance()->getSoldierHp((SoldierType)_createSoldierCursor);
	return _currentHp >= needHp;
}

int HeadQuarter::addSoldierCursor()
{
	++_createSoldierCursor;
	if (_createSoldierCursor > SOLIDER_TYPE_NUM)
	{
		_createSoldierCursor = 0;
	}
	return _createSoldierCursor;
}

bool HeadQuarter::checkCanCreateMinHpSoldier() const
{
	bool canCraeteflag = false;
	for (int i = 0; i < SOLIDER_TYPE_NUM; i++)
	{
		SoldierType soldierType = getSoldierTypeInBook(i);
		float soldierHp = GameConfig::GetInstance()->getSoldierHp(soldierType);
		if (_currentHp >= soldierHp)
		{
			canCraeteflag = true;
		}
	}
	return canCraeteflag;
}

SoldierType HeadQuarter::getSoldierTypeInBook(int index) const
{
	return SoliderBook[_soliderBook][index];
}

Soldier* HeadQuarter::addSoldier(SoldierType soldierType)
{
	//创建士兵
	_createNum++;
	auto soldier = SoldierManager::GetInstance()->CreateSoldierByType(soldierType,this ,_createNum);
	if (soldier)
	{
		soldier->init(this);
		//扣血
		float soldierHp = GameConfig::GetInstance()->getSoldierHp(soldierType);
		addHp(-soldierHp);
		return soldier;
	}
	else
	{
		return nullptr;
	}
}


void HeadQuarter::update(time_t dt)
{
	//尝试创建士兵
	Soldier* newSoldier = tryAddSoldier();
	if (!newSoldier)
	{
		std::cout << getName() << " create soldier failed!" << std::endl;
	}
	else
	{
		std::cout << GameUtils::GetInstance()->getTimeStamp() << " " << newSoldier->getName() << " " << newSoldier->getCreateNumber() <<
			" born with strength " << newSoldier->getOrigalHp() << ","
			<< getSoldierNumberByType(newSoldier->getType()) << " " << newSoldier->getName() << " in " << getName() << std::endl;

		std::cout << newSoldier->getBornMsg() << std::endl;
	}
}

std::string HeadQuarter::getName() const
{
	std::string name = "";
	if (_camp == RED)
	{
		name.append("red");
	}
	else
	{
		name.append("blue");
	}
	name.append("headquarter");
	return name;
}

unsigned int HeadQuarter::getSoldierNumberByType(SoldierType soldierType) const
{
	unsigned int num = 0;
	auto targetSoldiers = SoldierManager::GetInstance()->getAliveSoliderByCityID(_cityID);
	for each (auto &pSoldier in targetSoldiers)
	{
		if (pSoldier->getType() == soldierType)
		{
			num++;
		}
	}
	return num;
}

