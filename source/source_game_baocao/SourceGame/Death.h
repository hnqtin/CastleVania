#pragma once
#include "Enemy.h"
#include"List.h"
#include"DeathWeapon.h"
enum DEATH_STATE
{
	DEATH_STATE_INACTIVE,
	DEATH_STATE_WAIT,
	DEATH_STATE_FLY,
};
class Death :
	public Enemy
{
	DEATH_STATE deathState;
	DelayTime waitDelay;
	int movingDirection;
	GameTime createWeaponTime;
public:
	void update(float dt) override;
	void setVx(float vx) override;
	void setAlive(bool alive) override;
	void restoreLocation() override;
	void setHealth(int health) override;
	Death();
	~Death();
};

