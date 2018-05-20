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

double PhysicsBox::getTimeGame()
{
	return _FpsManager->getTimeGame();
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
	double time = getTimeGame();
	if (isPhysicsEnable())
	{
		setVx(getVx() + getAx()*time);
		setVy(getVy() + getAy()*time);
		setDx(getVx()*time);
		setDy(getVy()*time);
	}
}
