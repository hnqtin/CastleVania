#include "Bridge.h"
#include"SimonPlayer.h"


Bridge::Bridge()
{
	setPhysicsEnable(false);
	setDx(-1);
}

void Bridge::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		setDx(nx * abs(getDx()));
	}
	auto simon = SimonPlayer::getInstance();
	if (other == simon)
	{
		simon->setContactObject(this);
		simon->setState(SIMON_PLAYER_STATE_ON_BRIDGE);
		simon->preventMoveWhenCollision(collisionTime, nx, ny);
		if (ny == 1)
		{
			simon->setIsOnGround(true);
		}
	}
}

void Bridge::restoreLocation()
{
	setDx(-1);
	MovableObject::restoreLocation();
}


Bridge::~Bridge()
{
}
