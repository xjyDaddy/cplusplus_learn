#pragma once
#include "Soldier.h"
class Ninjia :
	public Soldier
{
public:
	Ninjia(SoldierType soldierType,HeadQuarter* parent, int createNumber);
	virtual std::string getBornMsg() const;
	~Ninjia();
};

