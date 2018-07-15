#include "Enemy.h"
#include"Player.h"
#include"ScoreBar.h"

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

void Enemy::onDeath()
{
}

void Enemy::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	MovableObject::onCollision(other, nx, ny, collisionTime);
}

void Enemy::onIntersect(MovableBox * other)
{
	//xu ly khi enemy cham vao player
	auto player = Player::getInstance();
	if (other == player && !player->blinkDelay.isOnTime())
	{
		onContactPlayer();
	}
	if (other->getCollisionType() == CT_WEAPON)
	{
		setHealth(getHealth() - 1);
		if (getHealth() == 0)
		{
			this->setAlive(false);
			onDeath();
		}
	}
}

void Enemy::restoreLocation()
{
	setHealth(1);
	BaseObject::restoreLocation();
}

void Enemy::onContactPlayer()
{
	auto player = Player::getInstance();
	auto camera = Camera::getInstance();
	player->blinkDelay.start();
	player->setVy(getGlobalValue("player_hit_vy"));
	if (!player->getIsOnStair())
	{
		player->setAction(SIMON_PLAYER_ACTION_SIMON_INJURED);
		player->setIsOnGround(false);
		player->setDy(0);
		if (player->getX() > this->getX())
		{
			player->setVx(getGlobalValue("player_hit_vx"));
		}
		else
		{
			player->setVx(-getGlobalValue("player_hit_vx"));
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
