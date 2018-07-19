#include "Panther.h"
#include "Player.h"

REGISTER_OBJECT_GAME(Panther, SI_PANTHER)

void Panther::setPantherState(PANTHER_STATE pantherState)
{
	this->pantherState = pantherState;
}

void Panther::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (ny == 1)
	{
		Enemy::onCollision(other, nx, ny, collisionTime);
	}
	if (other->getCollisionType() == CT_GROUND && ny == 1 && pantherState == PANTHER_STATE_RUN &&
		((getDx() < 0 && getleft() <= other->getleft()) ||
		(getDx() > 0 && getRight() >= other->getRight()))
		)
	{
		setPantherState(PANTHER_STATE_JUMP);
		setDy(0);
		setIsOnGround(false);
		setVy(getGlobalValue("panther_vy_jump"));
		setVx(getDirection()* getGlobalValue("panther_vx"));
	}

}

void Panther::update(float dt)
{
	switch (pantherState)
	{
	case PANTHER_STATE_WAIT:
		setDirectionFollowPlayer();
		setDx(0);
		setVx(0);
		setVy(0);
		setDy(0);
		setAction(PANTHER_ACTION_WAIT);
		if (abs(getMidX() - Player::getInstance()->getMidX()) < getGlobalValue("panther_distance_to_activ"))
		{
			setPantherState(PANTHER_STATE_RUN);
			setDirectionFollowPlayer();
		}
		break;
	case PANTHER_STATE_JUMP:
		setAction(PANTHER_ACTION_JUMP);
		if (isOnGround())
		{
			setPantherState(PANTHER_STATE_RUN);
			setDirectionFollowPlayer();
			setVx(getDirection()*getGlobalValue("panther_vx"));
		}
		break;
	case PANTHER_STATE_RUN:
		setAction(PANTHER_ACTION_RUN);
		setVx(getDirection()*getGlobalValue("panther_vx"));
		break;
	default:
		break;
	}
	Enemy::update(dt);
}

void Panther::restoreLocation()
{
	setPantherState(PANTHER_STATE_WAIT);
	Enemy::restoreLocation();
}

Panther::Panther()
{
}


Panther::~Panther()
{
}
