#pragma once
#include "../GameConst.h"
#include <string>
class City
{
public:
	City(Camp camp, unsigned int cityID);
	~City();
	virtual void update(time_t dt);
	void addHp(float hp){ _currentHp += hp; };
	unsigned int getCityID() const { return _cityID; }

	float getHp() const{ return _currentHp;};
	Camp getCamp() const{ return _camp;};
	void setCamp(Camp camp) { _camp = camp; };

	virtual std::string getName() const;

protected:
	//势力
	Camp _camp;
	//剩余生命元
	float _currentHp;
	//最大生命元
	float _maxHp;
	//城市ID
	unsigned int _cityID;
	//
	unsigned long _UniqueID;

	CityType _type;
};

