#pragma once
#include"MovableObject.h"
class EnemyObject : public MovableObject
{
public:
	EnemyObject();
	~EnemyObject();

	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

