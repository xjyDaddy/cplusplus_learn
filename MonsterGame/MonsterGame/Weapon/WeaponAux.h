#pragma once
#include "Weapon.h"
#include "../GameConst.h"
class WeaponAux
{
public:
	static WeaponAux* GetInstance();
	static void DestroyInstace();
	void init();
	void destroy();
	Weapon* createWeaponByType(WeaponType weaponType ,Soldier* parent);
protected:
	WeaponAux();
	static WeaponAux* s_sharedWeaponAux;
};

