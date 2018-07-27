#pragma once
#include "BaseObject.h"
class BreakWall :
	public BaseObject
{
public:
	void onIntersect(MovableBox* other) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime) override;
	BreakWall();
	~BreakWall();
};

