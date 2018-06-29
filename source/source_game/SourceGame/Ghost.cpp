#include "Ghost.h"
#include"Player.h"

REGISTER_OBJECT_GAME(Ghost, SI_GHOST)

void Ghost::setGhostState(GHOST_STATE ghostState)
{
	this->ghostState = ghostState;
}

void Ghost::onInit(fstream & fs, int worldHeight)
{
	string name;
	fs >> name;
	int direction;
	fs >> direction;
	setDirection((Direction)direction);
	if (direction == -1)
	{
		setGhostState(GHOST_STATE::GHOST_STATE_VISIBLE);
	}
	else
	{
		setGhostState(GHOST_STATE::GHOST_STATE_INVISIBLE);
	}

}

void Ghost::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	Enemy::onCollision(other, nx, ny, collisionTime);
}

void Ghost::update()
{
	switch (ghostState)
	{
	case GHOST_STATE_INVISIBLE:
		setRenderActive(false);
		setVx(0);
		setDx(0);
		if (Player::getInstance()->getMidX() - getMidX() > getGlobalValue("ghost_distance_to_activ"))
		{
			setGhostState(GHOST_STATE_VISIBLE);
			setRenderActive(true);
		}
		break;
	case GHOST_STATE_VISIBLE:
		setVx(getGlobalValue("ghost_vx")*getDirection());
		Enemy::update();
		break;
	default:
		break;
	}
}

void Ghost::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == -1)
	{
		setGhostState(GHOST_STATE::GHOST_STATE_VISIBLE);
	}
	else
	{
		setGhostState(GHOST_STATE::GHOST_STATE_INVISIBLE);
	}
}

Ghost::Ghost()
{

}


Ghost::~Ghost()
{
}
