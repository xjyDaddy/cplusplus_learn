#pragma once
#include "Weapon.h"
class Arrow :
	public Weapon
{
public:
	Arrow(Soldier* parent);
	~Arrow();
	Soldier* findTarget() const;
	virtual bool attack();
	virtual void update(time_t dt);
private:
	unsigned int _useTimes;
};

