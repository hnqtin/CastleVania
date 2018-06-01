#include "Enemy.h"
#include"Player.h"


void Enemy::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - getMidX() < 0)
	{
		setDirection(Left);
	}
	else
	{
		setDirection(Right);
	}
}

void Enemy::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
