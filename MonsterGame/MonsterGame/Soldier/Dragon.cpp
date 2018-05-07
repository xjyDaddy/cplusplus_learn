#include "../stdafx.h"
#include "../City/HeadQuarter.h"
#include "Dragon.h"

Dragon::Dragon(SoldierType soldierType, HeadQuarter* parent, int createNumber) :Soldier(soldierType, parent,createNumber)
{
	//dragon�������n%3������
	WeaponType weaponType = (WeaponType)(_createNumber % 3);
	addWeapon(weaponType);
	//ʿ��ֵ
	_morale = _parent->getHp() / _maxHp;
}


Dragon::~Dragon()
{
}

std::string Dragon::getBornMsg() const
{
	std::string name;
	name.append("It has a ");
	name.append(_weapons[0]->getWeaponName());
	name.append(" ,and it's morale is ");
	char s[14];
	sprintf_s(s, "%10.2f", _morale);
	name.append(s);
	return name;
}

