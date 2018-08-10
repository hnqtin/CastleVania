#pragma once
#include "AdditionalObject.h"
#include"FollowPlayer.h"
#include"Attacker.h"
#include"PlayerWeaponVictim.h"
enum DEATH_WEAPON_STATE
{
	DEATH_WEAPON_STATE_WAIT,
	DEATH_WEAPON_STATE_RUN,
	DEATH_WEAPON_STATE_CONTINUE_RUN
};

class DeathWeapon :
	public AdditionalObject,
	public IPlayerWeaponVictim
{
	DEATH_WEAPON_STATE state;
	DelayTime waitDelay;
	DelayTime continueRunDelay;
	FollowPlayer followPlayer;
	PlayerWeaponVictim playerWeaponVictim;
	Attacker attacker;
	int targetX, targetY;
	int health;
public:
	static int weaponCounter;
	static List<DeathWeapon*> weapons;
	void update(float dt) override;
	void onIntersect(MovableBox* other) override;
	void setHealth(int health) override;
	int getHealth() override;
	void setAlive(bool alive)  override;
	DeathWeapon();
	~DeathWeapon();
};

