#pragma once
#include "BaseObject.h"
class WaterObj :
	public BaseObject
{
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime) override;
	WaterObj();
	~WaterObj();
};

