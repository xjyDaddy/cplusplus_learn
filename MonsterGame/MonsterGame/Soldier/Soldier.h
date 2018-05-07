#pragma once
#include <vector>
#include <string>
#include "../Weapon/Weapon.h"
#include "../GameConst.h"

class HeadQuarter;
class Soldier
{
public:
	Soldier(SoldierType soldierType, HeadQuarter* parent, int createNumber);
	virtual ~Soldier();
	SoldierType getType() const { return _type; };
	void init(HeadQuarter* headQuarter);
	HeadQuarter* getParent() const;
	void update(time_t dt);
	std::vector<Weapon*>& getWeapons() { return _weapons; };
	unsigned int getCreateNumber() const { return _createNumber;};

	virtual void addWeapon(WeaponType weaponType);
	virtual std::string getBornMsg() const;
	std::string getName() const{ return SOLDIER_NAME[(int)_type];};

	Camp getCamp() const;

	float getCurrentHp() const { return _currentHp;};
	float getMaxHp() const { return _maxHp; };
	float getOrigalHp() const;

	float getAttack() const{ return _attck;};
	void setCurrentCityID(unsigned int cityID) { _currentCityID = cityID; }
	unsigned int getCurrentCityID() const { return _currentCityID; };
	unsigned int getNextCityID() const;
	void getHpFromCity(float genHp);

	SoldierStatus getStatus() const { return _status; };
	void changeStatus(SoldierStatus status){ _status = status; };
	
	virtual bool doBeAttack(float damage);
	virtual bool doWalk();
	virtual bool doAttack();
	virtual bool doAttackBack();
	virtual bool isWillBeKilling();
protected:
	HeadQuarter* _parent;
	SoldierType _type;
	std::vector<Weapon*> _weapons;
	float _currentHp;
	float _maxHp;
	float _attck;
	unsigned int _currentCityID;
	int _ID;
	unsigned int _createNumber;
	SoldierStatus _status;
};

