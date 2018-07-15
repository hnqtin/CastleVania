#pragma once
#include"BaseObject.h"
class MovableObject : public BaseObject
{
	// doi tuong co dang o tren mat dat hay khong
	bool onGround;
	float dt;
protected:
public:
	float getDt();
	void setIsOnGround(bool onGround);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update(float dt) override;
	bool isOnGround();
	MovableObject();
	~MovableObject();
};

