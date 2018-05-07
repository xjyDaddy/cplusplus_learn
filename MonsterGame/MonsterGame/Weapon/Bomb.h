#pragma once
#include "Weapon.h"
class Bomb :
	public Weapon
{
public:
	Bomb(Soldier* parent);
	~Bomb();

	virtual void update(time_t dt);
};

