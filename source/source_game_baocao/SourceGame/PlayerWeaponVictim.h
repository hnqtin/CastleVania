#pragma once
#include"BaseObject.h"

class IPlayerWeaponVictim
{
public:
	virtual void setHealth(int health) = 0;
	virtual int getHealth() = 0;
	virtual void setAlive(bool alive) = 0;
};

class PlayerWeaponVictim
{
	IPlayerWeaponVictim * obj;
public:
	PlayerWeaponVictim(IPlayerWeaponVictim * obj);
	void onWeaponAttack();
	~PlayerWeaponVictim();
};

