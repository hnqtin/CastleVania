#include "MovableObject.h"



void MovableObject::setIsOnGround(bool onGround)
{
	this->onGround = onGround;
}

void MovableObject::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny == 1)
		{
			setIsOnGround(true);
			setVy(-10);
		}
	}
}

void MovableObject::update()
{
	BaseObject::update();
	setIsOnGround(false);
	updatePhysics();
}

bool MovableObject::isOnGround()
{
	return onGround;
}

MovableObject::MovableObject()
{
	setAy(getGlobalValue("default_gravity"));
}


MovableObject::~MovableObject()
{
}