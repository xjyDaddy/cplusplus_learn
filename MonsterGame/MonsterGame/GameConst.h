#pragma once

const int SOLIDER_TYPE_NUM = 5;
const int WEAPON_TYPE_NUM = 3;

enum SoldierType
{
	ICE_MAN,
	DRAGON,
	NINJA,
	WOLF,
	LION,
};

enum WeaponType
{
	SWORD,
	BOMB,
	ARROW,
};

enum CityType
{
	HEAD_QUARTER,
	NORMAL,
};

enum Camp
{
	NEUTRALITY,
	BLUE,
	RED,
};

enum SoldierStatus
{
	ALIVE,
	DEAD,
	RUN_AWAY,
};

const char WEAPON_NAME[WEAPON_TYPE_NUM][20] =
{
	"sword",
	"bomb",
	"arrow",
};

const char SOLDIER_NAME[SOLIDER_TYPE_NUM][20] =
{
	"ice man",
	"dragon",
	"ninja",
	"wolf",
	"blue lion"
};

const SoldierType SoliderBook[2][SOLIDER_TYPE_NUM] = {
	{ICE_MAN , LION , WOLF , NINJA , DRAGON},
	{LION, DRAGON, NINJA, ICE_MAN, WOLF}
};

struct CityData
{
	Camp camp;
	CityType type;
	float hp;
};

struct SoliderData
{
	SoldierType type;
	float attackValue;
	float defenceValue;
};

struct ArrowData
{
	unsigned int soldierFactor;
	unsigned int abrasionFactor;
};

struct SwordData
{
	unsigned int useTimes;
};

struct WeaponData
{
	WeaponType type;
	float attackValue;
};