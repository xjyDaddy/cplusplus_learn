#include "../stdafx.h"
#include "Ninjia.h"

Ninjia::Ninjia(SoldierType soldierType,HeadQuarter* parent, int createNumber) :Soldier(soldierType ,parent, createNumber)
{
	//Á½¼þÎäÆ÷
	WeaponType weaponType1 =  (WeaponType)(_createNumber % 3);
	WeaponType weaponType2 = (WeaponType)((_createNumber+1) % 3);

	addWeapon(weaponType1);
	addWeapon(weaponType2);
}


Ninjia::~Ninjia()
{

}

std::string Ninjia::getBornMsg() const
{
	std::string name;
	name.append("It has a ");
	name.append(_weapons[0]->getWeaponName());
	name.append(" ,and a ");
	name.append(_weapons[1]->getWeaponName());
	return name;
}

