#include "Fleaman.h"
#include"Camera.h"
#include"Collision.h"
REGISTER_OBJECT_GAME(Fleaman, SI_FLEAMAN)
extern int getRandom(int start, int end);

FLEAMAN_STATE Fleaman::chooseState()
{
	auto state = (FLEAMAN_STATE)getRandom(FLEAMAN_STATE_RUN, FLEAMAN_STATE_JUMP);
	setDirectionFollowPlayer();
	if (state == FLEAMAN_STATE_RUN)
	{
		setVx(getDirection()* getGlobalValue("fleaman_vx_run"));
		setVy(getGlobalValue("fleaman_vy_run"));
	}
	else
	{
		setVx(getDirection()*getGlobalValue("fleaman_vx_jump"));
		setVy(getGlobalValue("fleaman_vy_jump"));
	}
	return state;
}

void Fleaman::update(float dt)
{
	switch (fleamanState)
	{
	case FLEAMAN_STATE_WAIT:
	{
		setDirectionFollowPlayer();
		waitDelay.update();
		setAction(FLEAMAN_ACTION_RUN);
		Camera* camera = Camera::getInstance();
		if (Collision::AABBCheck(this, camera))
		{
			if (waitDelay.isTerminated())
			{
				fleamanState = chooseState();
			}
			if (!waitDelay.isOnTime())
			{
				waitDelay.start();
			}
		}
		break;
	}
	case FLEAMAN_STATE_RUN:
		setAction(FLEAMAN_ACTION_RUN);
		if (isOnGround())
		{
			fleamanState = chooseState();
		}
		break;
	case FLEAMAN_STATE_JUMP:
		setAction(FLEAMAN_ACTION_WAIT);
		if (isOnGround())
		{
			fleamanState = chooseState();
		}
		break;
	default:
		break;
	}
	Enemy::update(dt);
}

void Fleaman::restoreLocation()
{
	fleamanState = FLEAMAN_STATE_WAIT;
	Enemy::restoreLocation();
}

Fleaman::Fleaman()
{
	waitDelay.init(getGlobalValue("fleaman_wait_delay"));
}


Fleaman::~Fleaman()
{
}
