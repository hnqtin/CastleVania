#pragma once
#include "Enemy.h"

class LinhNhay :
	public Enemy
{
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	LinhNhay();
	~LinhNhay();
};

