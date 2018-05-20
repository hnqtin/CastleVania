#include "Enemy.h"



void Enemy::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
