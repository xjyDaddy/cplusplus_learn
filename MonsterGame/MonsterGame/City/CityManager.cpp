#include "../stdafx.h"
#include "CityManager.h"


CityManager::CityManager()
{
}

CityManager* CityManager::GetInstance()
{
	if (!s_sharedCityManager)
	{
		s_sharedCityManager = new CityManager();
		s_sharedCityManager->init();
	}
	return s_sharedCityManager;
}

void CityManager::DestroyInstace()
{
	if (s_sharedCityManager)
	{
		delete s_sharedCityManager;
	}
	s_sharedCityManager = nullptr;
}

void CityManager::init()
{

}

void CityManager::update(time_t dt)
{
	for each (auto& headQuarter in _citys)
	{
		headQuarter->update(dt);
	}
}

void CityManager::destroy()
{
	for each (auto& headQuarter in _citys)
	{
		delete headQuarter;
	}

	_citys.clear();
}

HeadQuarter* CityManager::createHeadQuarter(Camp camp, unsigned int cityID, unsigned int tragetCityID)
{
	auto headQuarter = new HeadQuarter(camp,cityID,tragetCityID);
	_citys.emplace_back(headQuarter);
	return headQuarter;
}

City* CityManager::createCity(Camp camp, unsigned int cityID)
{
	auto pCity = new City(camp, cityID);
	_citys.emplace_back(pCity);
	return pCity;
}

bool CityManager::isHeadQuarter(unsigned int cityID) const
{
	if (cityID == 0 || cityID == _citys.size() - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CityManager* CityManager::s_sharedCityManager = nullptr;

