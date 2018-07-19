#include "MovableBox.h"
#include"ConsoleLogger.h"
#include"Player.h"
int abs(int a)
{
	if (a > 0)
		return a;
	return -a;
}


void MovableBox::updateLocation()
{
	if (isCollision && !isChangeDxOrDy)
	{
		if (abs((int)getDx()) > abs((int)dy))
			setDy(0);
		else
			setDx(0);
	}

	setX((int)(getX() + getDx() + 0.5));
	setY((int)(getY() + getDy() + 0.5));

	//move(getDx(), getDy());
}

bool MovableBox::canCollision()
{
	return true;
}

void MovableBox::onIntersect(MovableBox * other)
{
}
COLLISION_TYPE MovableBox::getCollisionType()
{
	return this->collisionType;
}

void MovableBox::setCollisionType(int collisionType)
{
	this->collisionType = (COLLISION_TYPE)collisionType;
}

void MovableBox::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{

}

void MovableBox::update()
{
	isCollision = false;
	isChangeDxOrDy = false;
}

void MovableBox::preventMoveWhenCollision(float collisionTime, int nx, int ny)
{
	setIsCollision(true);

	if (nx != 0)
	{
		isChangeDxOrDy = true;
		setDx(getDx()*collisionTime);
		return;
	}
	if (ny != 0)
	{
		isChangeDxOrDy = true;
		setDy(dy*collisionTime);
		return;
	}
}

MovableBox::MovableBox()
{
}


MovableBox::~MovableBox()
{
}

void MovableBox::setDx(float dx)
{
	this->dx = dx;
}

void MovableBox::setDy(float dy)
{
	this->dy = dy;
}

void MovableBox::setIsCollision(bool isCollision)
{
	this->isCollision = true;
}

float MovableBox::getDx()
{
	return this->dx;
}

float MovableBox::getDy()
{
	return this->dy;
}

float MovableBox::getNextFrameX()
{
	return getX() + dx;
}

float MovableBox::getNextFrameY()
{
	return getY() + dy;
}