#include "Meo.h"
#include "Player.h"

REGISTER_OBJECT_GAME(Meo, SI_MEO)

void Meo::setMeoState(MEO_STATE meoState)
{
	this->meoState = meoState;
}

void Meo::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	Enemy::onCollision(other, nx, ny, collisionTime);
}

void Meo::update()
{
	switch (meoState)
	{
	case MEO_STATE_WAIT:
		setVx(0);
		setVy(0);
		setAction(MEO_ACTION_WAIT);
		if (getMidX() - Player::getInstance()->getMidX() < getGlobalValue("meo_distance_to_activ"))
		{
			setMeoState(MEO_STATE_JUMP);
			setVy(getGlobalValue("meo_vy_jump"));
			setVx(-getGlobalValue("meo_vx"));
		}
		break;
	case MEO_STATE_JUMP:
		setAction(MEO_ACTION_JUMP);
		if (isOnGround())
		{
			setMeoState(MEO_STATE_RUN);
			setDirection(Right);
		}
		break;
	case MEO_STATE_RUN:
		setAction(MEO_ACTION_RUN);
		setVx(getGlobalValue("meo_vx"));
		break;
	default:
		break;
	}
	Enemy::update();
}

void Meo::restoreLocation()
{
	setMeoState(MEO_STATE_WAIT);
	setDirection(Left);
	Enemy::restoreLocation();
}

Meo::Meo()
{
	setDirection(Left);
}


Meo::~Meo()
{
}
