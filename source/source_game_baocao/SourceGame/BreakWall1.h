#pragma once
#include "BaseObject.h"
class BreakWall1 :
	public BaseObject
{
public:
	void onIntersect(MovableBox* other) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime) override;
	BreakWall1();
	~BreakWall1();
};

