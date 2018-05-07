#pragma once
class GameUtils
{
public:
	static GameUtils* GetInstance();
	static void DestroyInstance();
	unsigned long GenCityID();
	unsigned long GenSoldierID();
	unsigned long GenWeaponID();
	void addTimeStamp(time_t dt) { _timeStamp += dt;};
	time_t getTimeStamp()const { return _timeStamp; };
	time_t getTimeStampPerHour()const { return _timeStamp % 60; };
	bool init();
	void destroy();
protected:
	GameUtils();
	static GameUtils* s_sharedGameUtils;
	unsigned long _headCityID;
	unsigned long _soldierID;
	unsigned long _weaponID;
	time_t _timeStamp;
};

