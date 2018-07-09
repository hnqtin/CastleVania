#include "Enemy.h"
#include"Player.h"


void Enemy::setHealth(int health)
{
	this->health = health;
}

int Enemy::getHealth()
{
	return health;
}

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
	MovableObject::onCollision(other, nx, ny, collisionTime);
}

void Enemy::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		setHealth(getHealth() - 1);
		if (getHealth() == 0)
		{
			this->setAlive(false);
		}
	}
}

Enemy::Enemy()
{
	setHealth(1);
}


Enemy::~Enemy()
{
}
