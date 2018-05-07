#pragma once
#include <vector>
#include "GameConst.h"
class GameConfig
{
public:
	static GameConfig* GetInstance();
	static void DestroyInstance();
	bool init();
	void destroy();

	void loadSoldierHps(const std::vector<float>& soldierHp);
	void loadSoldierAttacks(const std::vector<float>& attacks);

	void loadCityOrigalHp(float cityOrigalHp){ _cityOrigalHp = cityOrigalHp; };
	void loadCityNum(unsigned int cityNum){ _cityNum = cityNum; };
	void loadArrowAttack(float arrowAttack){ _arrowAttack = arrowAttack; };
	void loadLionLoyaltyFactor(float factor){ _lionLoyaltyFactor = factor; };
	void loadSwordSoldierFactor(float factor){ _swordSoldierFactor = factor; };
	void loadSwordAbrasionFactor(float factor){ _swordAbrasionFactor = factor; };
	void loadArrowUseTimes(unsigned int times){ _arrowUseTimes = times; };

	float getSoldierHp(SoldierType soldierType) const;
	float getSoldierAttack(SoldierType soldierType) const;

	float getCityOrigalHp() const{ return _cityOrigalHp; };
	unsigned int getCityNum() const{ return  _cityNum; };
	float getArrowAttack() const{ return _arrowAttack; };
	float getLionLoyaltyFactor() const{ return _lionLoyaltyFactor; };
	float getSwordSoldierFactor() const{ return _swordAbrasionFactor; };
	float GetSwordAbrasionFactor() const{ return _swordAbrasionFactor; };
	unsigned int GetArrowUseTimes() const{ return _arrowUseTimes; };

protected:
	GameConfig();
	static GameConfig* s_sharedGameConfig;
	std::vector<float> _soldierHp;
	std::vector<float> _soldierAttack;
	std::vector<float> _headQuarterHp;

	float _cityOrigalHp;
	unsigned int _cityNum;
	float _arrowAttack;
	float _lionLoyaltyFactor;
	float _swordSoldierFactor;
	float _swordAbrasionFactor;
	unsigned int _arrowUseTimes;
};

