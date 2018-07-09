#include "Zombie.h"
#include"Player.h"

REGISTER_OBJECT_GAME(Zombie, SI_ZOMBIE)


void Zombie::setZombieState(ZOMBIE_STATE zombieState)
{
	this->zombieState = zombieState;
}

void Zombie::onInit(fstream & fs, int worldHeight)
{
	string name;
	fs >> name;
	int direction;
	fs >> direction;
	setDirection((Direction)direction);
	if (direction == -1)
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_VISIBLE);
	}
	else
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_INVISIBLE);
	}

}

void Zombie::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		this->setAlive(false);
	}
}

void Zombie::setDx(float dx)
{
	Enemy::setDx(dx);
}

void Zombie::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (nx != 0)
		return;
	Enemy::onCollision(other, nx, ny, collisionTime);
}

void Zombie::update(float dt)
{
	switch (zombieState)
	{
	case ZOMBIE_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (Player::getInstance()->getMidX() - getMidX() > getGlobalValue("zombie_distance_to_activ"))
		{
			setZombieState(ZOMBIE_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case ZOMBIE_STATE_VISIBLE:
		setVx(getGlobalValue("zombie_vx")*getDirection());
		Enemy::update(dt);
		break;
	default:
		break;
	}
}

void Zombie::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == -1)
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_VISIBLE);
	}
	else
	{
		setZombieState(ZOMBIE_STATE::ZOMBIE_STATE_INVISIBLE);
	}
}

Zombie::Zombie()
{

}


Zombie::~Zombie()
{
}
