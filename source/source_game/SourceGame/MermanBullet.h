#pragma once
#include "AdditionalObject.h"
class MermanBullet :
	public AdditionalObject
{
public:
	MermanBullet();
	~MermanBullet();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

