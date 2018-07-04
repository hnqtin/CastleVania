#pragma once
#include"BaseObject.h"
class MovableObject : public BaseObject
{
	// doi tuong co dang o tren mat dat hay khong
	bool onGround;
protected:
public:
	void setIsOnGround(bool onGround);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update(float dt) override;
	bool isOnGround();
	MovableObject();
	~MovableObject();
};

