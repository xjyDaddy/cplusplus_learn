#pragma once
#include "Soldier.h"
class Lion :
	public Soldier
{
public:
	Lion(SoldierType soldierType,HeadQuarter* parent,int createNumber);
	virtual void update(time_t dt);
	~Lion();
	virtual std::string getBornMsg() const;
	void doRunAway();
protected:
	bool checkRunAway() const;

	float _loyalty;
};

