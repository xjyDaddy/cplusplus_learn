#pragma once
#include "Soldier.h"
class IceMan:public Soldier
{
public:
	IceMan(SoldierType soldierType,HeadQuarter* parent ,int createNumber);
	virtual std::string getBornMsg() const;
	~IceMan();

private:

};

