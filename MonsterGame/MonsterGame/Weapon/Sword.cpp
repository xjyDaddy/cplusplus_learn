#include "../stdafx.h"
#include "Sword.h"

Sword::Sword(Soldier* parent):Weapon(parent)
{
	_type = WeaponType::SWORD;
}


Sword::~Sword()
{
}
