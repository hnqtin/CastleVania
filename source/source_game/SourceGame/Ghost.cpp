#include "Ghost.h"
#include"Player.h"

REGISTER_OBJECT_GAME(Ghost, SI_GHOST)

void Ghost::setGhostState(GHOST_STATE ghostState)
{
	this->ghostState = ghostState;
}

void Ghost::onInit(fstream & fs)
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
	int d = getGlobalValue("ghost_distance_to_activ");
	switch (ghostState)
	{
	case GHOST_STATE_INVISIBLE:
		setRenderActive(false);
		if (Player::getInstance()->getMidX() - getMidX() > d)
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
