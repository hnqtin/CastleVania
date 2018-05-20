#pragma once
#include "Enemy.h"

class Simon :
	public Enemy
{
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	Simon();
	~Simon();
};

