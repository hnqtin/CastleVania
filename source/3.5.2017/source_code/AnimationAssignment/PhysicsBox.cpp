#include "PhysicsBox.h"



PhysicsBox::PhysicsBox()
{
	setPhysicsEnable(true);
}


PhysicsBox::~PhysicsBox()
{
}



void PhysicsBox::setVx(float vx)
{
	this->vx = vx;
}

void PhysicsBox::setVy(float vy)
{
	this->vy = vy;
}

void PhysicsBox::setAx(float ax)
{
	this->ax = ax;
}

void PhysicsBox::setAy(float ay)
{
	this->ay = ay;
}
float PhysicsBox::getVx()
{
	return this->vx;
}

float PhysicsBox::getVy()
{
	return this->vy;
}

float PhysicsBox::getAx()
{
	return this->ax;
}

float PhysicsBox::getAy()
{
	return this->ay;
}

bool PhysicsBox::isPhysicsEnable()
{
	return physicsEnable;
}

void PhysicsBox::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

void PhysicsBox::updatePhysics()
{
	int time = 20;
	if (isPhysicsEnable())
	{
		setVx(getVx() + getAx()*time);
		setVy(getVy() + getAy()*time);
		setDx(getVx()*time);
		setDy(getVy()*time);
	}
}
