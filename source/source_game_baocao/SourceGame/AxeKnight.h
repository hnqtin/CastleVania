#pragma once
#include "Enemy.h"
#include"AxeKnightWeapon.h"
class AxeKnight :
	public Enemy
{
	GameTime throwTime;
	List<AxeKnightWeapon*> weapons;
public:
	void update(float dt) override;
	void updateLocation() override;
	void restoreLocation() override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime)override;
	AxeKnight();
	~AxeKnight();
};

