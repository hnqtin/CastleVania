#pragma once
#include "MovableObject.h"
class Bridge :
	public MovableObject
{
public:
	Bridge();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void restoreLocation();
	~Bridge();
};

