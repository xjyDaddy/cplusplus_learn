#pragma once
#include <vector>
#include "HeadQuarter.h"
class CityManager
{
public:
	static CityManager* GetInstance();
	static void DestroyInstace();
	void init();
	void destroy();
	HeadQuarter* createHeadQuarter(Camp camp, unsigned int cityID, unsigned int tragetCityID);
	bool isHeadQuarter(unsigned int cityID) const;
	City* createCity(Camp camp, unsigned int cityID);
	void update(time_t dt);
protected:
	CityManager();
	static CityManager* s_sharedCityManager;
	std::vector<City*> _citys;
};

