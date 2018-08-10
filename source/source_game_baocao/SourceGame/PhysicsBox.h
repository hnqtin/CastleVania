#pragma once
#include"MovableBox.h"
class PhysicsBox : public MovableBox
{
	float vx, vy, ax, ay;
	bool physicsEnable;
public:
	virtual void setVx(float vx);
	void setVy(float vy);
	void setAx(float ax);
	void setAy(float ay);
	float getVx();
	float getVy();
	float getAx();
	float getAy();

	bool isPhysicsEnable();
	void setPhysicsEnable(bool physicsEnable);

	void updatePhysics(float dt);

	PhysicsBox();
	~PhysicsBox();
};

