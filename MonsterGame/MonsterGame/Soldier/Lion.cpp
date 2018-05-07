#include "../stdafx.h"
#include "../City/HeadQuarter.h"
#include "../GameUtils.h"
#include "Lion.h"

Lion::Lion(SoldierType soldierType, HeadQuarter* parent,int createNumber) :Soldier(soldierType,parent , createNumber)
{
	_loyalty = _parent->getHp();
}


Lion::~Lion()
{
}

std::string Lion::getBornMsg() const
{
	std::string name;
	name.append("It's loyalty is ");
	char s[14];
	sprintf_s(s, "%10.2f", _loyalty);
	name.append(s);
	return name;
}

void Lion::update(time_t dt)
{
	if (GameUtils::GetInstance()->getTimeStampPerHour() == 5)
	{
		if (checkRunAway())
		{
			doRunAway();
		}
	}
}

bool Lion::checkRunAway() const
{
	return _loyalty <= 0;
}

void Lion::doRunAway()
{
	_status = RUN_AWAY;
}
