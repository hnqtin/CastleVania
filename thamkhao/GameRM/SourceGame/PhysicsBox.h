#pragma once
#include"MovableBox.h"
#include"FpsManager.h"
class PhysicsBox : public MovableBox
{
	float vx, vy, ax, ay;
	bool physicsEnable;
public:
	void setVx(float vx);
	void setVy(float vy);
	void setAx(float ax);
	void setAy(float ay);
	float getVx();
	float getVy();
	float getAx();
	float getAy();
	double getTimeGame();

	bool isPhysicsEnable();
	void setPhysicsEnable(bool physicsEnable);

	void updatePhysics();

	PhysicsBox();
	~PhysicsBox();
};

