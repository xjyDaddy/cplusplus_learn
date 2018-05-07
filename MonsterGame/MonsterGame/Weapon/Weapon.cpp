#include "../stdafx.h"
#include "Weapon.h"
#include "../GameUtils.h"

Weapon::Weapon(Soldier* soldier)
{
	_ID = GameUtils::GetInstance()->GenWeaponID();
	_parent = soldier;
}

Weapon::~Weapon()
{

}

void Weapon::update(time_t dt)
{
}

bool Weapon::attack()
{
	return true;
}
