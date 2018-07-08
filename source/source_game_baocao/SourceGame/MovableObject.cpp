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
		}

		if (ny != 0)
		{
			setVy(-10);
		}

		preventMoveWhenCollision(collisionTime, nx, ny);
	}
}

void MovableObject::update(float dt)
{
	BaseObject::update(dt);
	setIsOnGround(false);
	updatePhysics(dt);
}

bool MovableObject::isOnGround()
{
	return onGround;
}

MovableObject::MovableObject()
{
	setAy(getGlobalValue("game_gravity"));
}


MovableObject::~MovableObject()
{
}
