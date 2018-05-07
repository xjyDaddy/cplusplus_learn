#include "../stdafx.h"
#include "../GameConfig.h"
#include "../City/HeadQuarter.h"
#include "../GameUtils.h"
#include "../Weapon/WeaponAux.h"
#include "Soldier.h"

Soldier::Soldier(SoldierType soldierType, HeadQuarter* parent,int createNumber)
{
	_ID = GameUtils::GetInstance()->GenSoldierID();
	_type = soldierType;
	_createNumber = createNumber;
	_maxHp = getOrigalHp();
	_currentHp = _maxHp;
	_parent = parent;
	_currentCityID = parent->getCityID();
}


Soldier::~Soldier()
{
	for each (auto & pWeapon in _weapons)
	{
		delete pWeapon;
	}
	_weapons.clear();
}

void Soldier::init(HeadQuarter* headQuarter)
{
	_parent = headQuarter;
}

void Soldier::update(time_t dt)
{
	for each (auto& pWeapon in _weapons)
	{
		pWeapon->update(dt);
	}

	if (GameUtils::GetInstance()->getTimeStampPerHour() == 10)
	{
		doWalk();
	}
}

HeadQuarter* Soldier::getParent() const
{
	return _parent;
}

float Soldier::getOrigalHp() const
{
	return GameConfig::GetInstance()->getSoldierHp(_type);
}

void Soldier::addWeapon(WeaponType weaponType)
{
	auto weapon = WeaponAux::GetInstance()->createWeaponByType(weaponType , this);
	_weapons.emplace_back(weapon);
}

std::string Soldier::getBornMsg() const
{
	return "";
}


bool Soldier::doAttackBack()
{
	return true;
}

bool Soldier::doAttack()
{
	return true;
}

bool Soldier::doWalk()
{
	_currentCityID = getNextCityID();
	return true;
}

bool Soldier::isWillBeKilling()
{
	return true;
}

void Soldier::getHpFromCity(float genHp)
{
	//传送给司令部
	_parent->addHp(genHp);
}

unsigned int Soldier::getNextCityID() const
{
	unsigned int nextID = _currentCityID;
	int cursor = (_parent->getTargetCityID() > _parent->getCityID()) ? 1 : -1;
	if (cursor*(_currentCityID + cursor) <= cursor * _parent->getCityID())
	{
		nextID = _currentCityID + cursor;
	}
	return nextID;
}

Camp Soldier::getCamp() const
{
	return _parent->getCamp();
}

bool Soldier::doBeAttack(float damage)
{
	return true;
}

