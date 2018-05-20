#pragma once
#include "MovableObject.h"
class Enemy :
	public MovableObject
{
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	Enemy();
	~Enemy();
};

