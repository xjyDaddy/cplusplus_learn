#pragma once
#include "Soldier.h"
class Dragon :
	public Soldier
{
public:
	Dragon(SoldierType soldierType,HeadQuarter* parent ,int createNumber);
	virtual std::string getBornMsg() const;
	~Dragon();
protected:
	float _morale;
};

