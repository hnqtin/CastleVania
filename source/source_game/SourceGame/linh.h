#pragma once
#include "Enemy.h"
class linh :
	public Enemy
{
public:
	void update();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	linh();
	~linh();
};

