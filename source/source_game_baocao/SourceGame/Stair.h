#pragma once
#include "BaseObject.h"
class Stair :
	public BaseObject
{
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	Stair();
	~Stair();
};

