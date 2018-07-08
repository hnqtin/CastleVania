#include "MermanBullet.h"


MermanBullet::MermanBullet()
{
	setSprite(SpriteManager::getSprite(SI_MERMAN_BULLET));
	setWidth(getSprite()->getFrameWidth(0, 0));
	setHeight(getSprite()->getFrameHeight(0, 0));
	setCollisionType(CT_ENEMY);
	setAy(0);
}


MermanBullet::~MermanBullet()
{
}

void MermanBullet::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
}
