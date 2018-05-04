#include "SmallHeart.h"
#include"SpriteManager.h"


SmallHeart::SmallHeart()
{
	setSprite(SpriteManager::getInstance()->getSprites()[SI_SMALL_HEART]);
	setAy(-0.0004);
	setSize(8, 8);
}


SmallHeart::~SmallHeart()
{
}

void SmallHeart::update()
{
	updatePhysics();
	BaseObject::update();
}

void SmallHeart::onIntersect(MovableBox * other)
{
	Item::onIntersect(other);
}

void SmallHeart::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny != 0)
			setVy(-0.1f); //****
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
	BaseObject::onCollision(other, nx, ny, collisionTime);
}
