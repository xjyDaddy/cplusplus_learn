#include "../stdafx.h"
#include "Arrow.h"
#include "../GameConfig.h"
#include "../City/CityManager.h"
#include "../Soldier/SoldierManager.h"
#include "../Soldier/Soldier.h"
#include "../GameUtils.h"
Arrow::Arrow(Soldier* parent):Weapon(parent)
{
	_type = WeaponType::ARROW;
	_useTimes = GameConfig::GetInstance()->GetArrowUseTimes();
	_attack = GameConfig::GetInstance()->getArrowAttack();
}


Arrow::~Arrow()
{

}

bool Arrow::attack()
{
	if (_useTimes == 0)
	{
		return false;
	}
	auto findObj = findTarget();
	findObj->doBeAttack(_attack);
	return true;
}

Soldier* Arrow::findTarget() const
{
	unsigned int nextID = _parent->getNextCityID();
	if (CityManager::GetInstance()->isHeadQuarter(nextID))
	{
		return nullptr;
	}
	else
	{
		Camp camp = _parent->getCamp() == BLUE ? RED : BLUE;
		auto targetSoldiers = SoldierManager::GetInstance()->getAliveSoliderByCityID(nextID, camp);
		auto randomNum = rand() % targetSoldiers.size();
		return targetSoldiers[randomNum];
	}
}

void Arrow::update(time_t dt)
{
	if (GameUtils::GetInstance()->getTimeStampPerHour() == 35)
	{
		attack();
	}
}
