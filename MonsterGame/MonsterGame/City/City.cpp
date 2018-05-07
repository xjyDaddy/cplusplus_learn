#include "../stdafx.h"
#include "City.h"
#include "../GameUtils.h"
#include "../GameConfig.h"
#include "../Soldier/SoldierManager.h"
#include <string>
City::City(Camp camp, unsigned int cityID) :_camp(camp), _cityID(cityID)
{
	_currentHp = GameConfig::GetInstance()->getCityOrigalHp();
	_maxHp = _currentHp;
	_type = NORMAL;
};


City::~City()
{
}

std::string City::getName() const
{
	std::string s = "city";
	return s;
}

void City::update(time_t dt)
{
	time_t timeStampPerHour = GameUtils::GetInstance()->getTimeStampPerHour();
	if (timeStampPerHour == 20)
	{
		_currentHp += 10;
	}
	else if (timeStampPerHour == 30)
	{
		auto targetSoldiers = SoldierManager::GetInstance()->getAliveSoliderByCityID(_cityID);
		if (targetSoldiers.size() == 1)
		{
			targetSoldiers[0]->getHpFromCity(_currentHp);
		}
	}
}
