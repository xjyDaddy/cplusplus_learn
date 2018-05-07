#include "../stdafx.h"
#include "WeaponAux.h"
#include "Arrow.h"
#include "Bomb.h"
#include "Sword.h"

WeaponAux* WeaponAux::GetInstance()
{
	if (!s_sharedWeaponAux)
	{
		s_sharedWeaponAux = new WeaponAux();
		s_sharedWeaponAux->init();
	}
	return s_sharedWeaponAux;
}

void WeaponAux::DestroyInstace()
{
	if (s_sharedWeaponAux)
	{
		delete s_sharedWeaponAux;
	}
	s_sharedWeaponAux = nullptr;
}

Weapon* WeaponAux::createWeaponByType(WeaponType weaponType , Soldier* parent)
{
	Weapon* newWeapon = nullptr;
	switch (weaponType)
	{
	case SWORD:
		newWeapon = new Sword(parent);
		break;
	case BOMB:
		newWeapon = new Bomb(parent);
		break;
	case ARROW:
		newWeapon = new Arrow(parent);
		break;
	default:
		newWeapon = nullptr;
		break;
	}
	return newWeapon;
}

void WeaponAux::init()
{

}

void WeaponAux::destroy()
{

}

WeaponAux::WeaponAux()
{

}

WeaponAux* WeaponAux::s_sharedWeaponAux = nullptr;
