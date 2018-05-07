#pragma once
#include "../GameConst.h"
#include <string>

class Soldier;

class Weapon
{
public:
	Weapon(Soldier* soldier);
	~Weapon();
	virtual void update(time_t dt);
	virtual std::string getWeaponName() const{ return WEAPON_NAME[(int)_type]; };
	WeaponType getType() const { return _type; };
	float getAttack() const{ return _attack; };
	void setAttack(float attack){ _attack = attack; }
	Soldier* getParent() const { return _parent; }

	virtual bool attack();
protected:
	WeaponType _type;
	unsigned long _ID;
	unsigned int _number;
	float _attack;
	Soldier* _parent;
};

