#pragma once
#include "AdditionalObject.h"
class MermanBullet :
	public AdditionalObject
{
	int health;
public:
	MermanBullet();
	~MermanBullet();
	bool canAttackPlayer() { return true; }
	void onIntersect(MovableBox* other) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

