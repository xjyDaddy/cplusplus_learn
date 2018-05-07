#include "../stdafx.h"
#include "../GameUtils.h"
#include "Bomb.h"


Bomb::Bomb(Soldier* parent) :Weapon(parent)
{
	_type = WeaponType::BOMB;
}


Bomb::~Bomb()
{
}

void Bomb::update(time_t dt)
{
	time_t time = GameUtils::GetInstance()->getTimeStamp();
	if(time%60 == 38)
	{
		;
	}
}
