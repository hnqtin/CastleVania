#pragma once
#include "AdditionalObject.h"
#include"Attacker.h"
#include"PlayerWeaponVictim.h"
enum AXEKNIGHTWEAPON_WEAPON_STATE
{
	AXEKNIGHTWEAPON_WEAPON_STATE_GO_HEAD,
	AXEKNIGHTWEAPON_WEAPON_STATE_GO_RETURN,
};

class AxeKnightWeapon :
	public AdditionalObject,
	public IPlayerWeaponVictim
{
	float alpha;
	GameTime timeRotation;
	Attacker attacker;
	PlayerWeaponVictim playerWeaponVictim;
	int health;
public:
	AXEKNIGHTWEAPON_WEAPON_STATE axeKnightWeaponState;
	int startX;
	void onIntersect(MovableBox* other)override;
	void setHealth(int health) override;
	int getHealth() override;
	void setAlive(bool alive) override;
	void update(float dt);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime)override;
	void render() override;
	AxeKnightWeapon();
	~AxeKnightWeapon();
};

