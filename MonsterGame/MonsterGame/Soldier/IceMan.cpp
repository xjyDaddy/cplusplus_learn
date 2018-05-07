#include "../stdafx.h"
#include "IceMan.h"


IceMan::IceMan(SoldierType soldierType,HeadQuarter* parent ,int createNumber) :Soldier(soldierType,parent ,createNumber)
{
	WeaponType weaponType = (WeaponType)(_createNumber % 3);
	addWeapon(weaponType);
}


IceMan::~IceMan()
{
}

std::string IceMan::getBornMsg() const
{
	std::string name;
	name.append("It has a ");
	name.append(_weapons[0]->getWeaponName());
	return name;
}
