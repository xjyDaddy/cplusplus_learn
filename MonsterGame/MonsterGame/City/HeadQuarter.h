#pragma once
#include <string>
#include <list>
#include "../Soldier/Soldier.h"
#include "../GameConst.h"
#include "City.h"
class HeadQuarter: public City
{
public:
	HeadQuarter(Camp camp, unsigned int cityID, unsigned int targetCityID);
	virtual ~HeadQuarter();
	Soldier* tryAddSoldier();
	virtual void update(time_t dt);
	unsigned int getSoldierNumberByType(SoldierType soldierType) const;
	virtual std::string getName() const;

	unsigned int getTargetCityID() const{ return _targetCityID; };
protected:
	Soldier* addSoldier(SoldierType soldierType);
	bool checkHpEnoughBySoldierType() const;
	int addSoldierCursor();
	bool checkCanCreateMinHpSoldier() const;
	SoldierType getSoldierTypeInBook(int index) const;
	SoldierType getCurrentCreateSoliderType() const;
protected:
	//����ʿ�����α�
	int _createSoldierCursor;  
	//ʿ���䷽ID
	int _soliderBook;
	//��������
	unsigned int _createNum;
	//Ŀ�����
	unsigned int _targetCityID;
};