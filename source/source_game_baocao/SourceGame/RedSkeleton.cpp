#include "RedSkeleton.h"
#include"ScoreBar.h"
#include"MorningStarAttack.h"
REGISTER_OBJECT_GAME(RedSkeleton, SI_RED_SKELETON)

void RedSkeleton::update(float dt)
{
	dieDelay.update();
	switch (redskeletonState)
	{
	case RED_SKELETON_STATE_RUN:
	{
		setCollisionType(CT_ENEMY);
		int begin = getInitBox()->getX() - getGlobalValue("redskeleton_distance");
		int end = getInitBox()->getX() + getGlobalValue("redskeleton_distance");
		if (getX() < begin)
		{
			setDirection(Right);
		}
		if (getX() > end)
		{
			setDirection(Left);
		}

		setVx(getDirection()* getGlobalValue("redskeleton_vx"));
		break;
	}
	case RED_SKELETON_STATE_DYING:
		setCollisionType(CT_NONE);
		setVx(0);
		if (getIsLastFrame())
		{
			redskeletonState = RED_SKELETON_STATE_DIE;
			dieDelay.start();
			setAction(RED_SKELETON_ACTION_DIE);
		}
		break;
	case RED_SKELETON_STATE_DIE:
		setVx(0);
		if (dieDelay.isTerminated())
		{
			setAction(RED_SKELETON_STATE_RESTORE);
			redskeletonState = RED_SKELETON_STATE_RESTORE;
		}
		break;
	case RED_SKELETON_STATE_RESTORE:
		setVx(0);
		if (getIsLastFrame())
		{
			redskeletonState = RED_SKELETON_STATE_RUN;
			setAction(RED_SKELETON_STATE_RUN);
		}
		break;
	default:
		break;
	}

	Enemy::update(dt);
}

void RedSkeleton::onContactWeapon()
{
	if (redskeletonState == RED_SKELETON_STATE_RUN)
	{
		setAction(RED_SKELETON_ACTION_DYING);
		redskeletonState = RED_SKELETON_STATE_DYING;
	}
}

void RedSkeleton::onIntersect(MovableBox * other)
{
	//xu ly khi enemy cham vao player
	auto player = Player::getInstance();
	if (other == player && !player->blinkDelay.isOnTime() && canAttackPlayer() && !player->isDead)
	{
		if (redskeletonState == RED_SKELETON_STATE_RUN)
		{
			onContactPlayer();
			ScoreBar::getInstance()->increaseHealth(-1);
			if (ScoreBar::getInstance()->getHealth() <= 0)
			{
				player->isDead = true;
				player->deadDelay.start();
			}
		}
	}
	if (other->getCollisionType() == CT_WEAPON)
	{
		((MorningStarAttack*)other)->setNeedDelete(true);
		onContactWeapon();
	}
}


RedSkeleton::RedSkeleton()
{
	setDirection(Right);
	dieDelay.init(getGlobalValue("redskeleton_die_delay"));
}


RedSkeleton::~RedSkeleton()
{
}
