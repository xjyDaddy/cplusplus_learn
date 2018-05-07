#pragma once
#include "Soldier.h"
class Wolf :
	public Soldier
{
public:
	Wolf(SoldierType soldierType,HeadQuarter* parent, int createNumber);
	~Wolf();
};

