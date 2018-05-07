#pragma once
#include <vector>
#include "../GameConst.h"
#include "Soldier.h"
class SoldierManager
{
public:
	static SoldierManager* GetInstance();
	static void DestroyInstace();
	void CleanSoldiers();
	void init();
	void update(time_t dt);
	void destroy();
	Soldier* CreateSoldierByType(SoldierType soldierType ,HeadQuarter* parent, unsigned int createNumber);
	std::vector<Soldier*> getAliveSoliderByCityID(unsigned int cityID) const;
	std::vector<Soldier*> getAliveSoliderByCityID(unsigned int cityID , Camp camp) const;
protected:
	SoldierManager();
	static SoldierManager* s_sharedSoldierManager;
	std::vector<Soldier*> _soldiers;
};

