#pragma once
#include"BaseObject.h"
class MovableObject : public BaseObject
{
	bool onGround;
protected:
public:
	void setIsOnGround(bool onGround);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	bool isOnGround();
	MovableObject();
	~MovableObject();
};

