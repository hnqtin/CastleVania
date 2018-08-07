#include "Skeleton.h"

#include"SkeletonWeapon.h"

REGISTER_OBJECT_GAME(Skeleton,SI_SKELETON)
extern int getRandom(int start, int end);

void Skeleton::refreshActivityArea()
{
	auto player = Player::getInstance();
	if (getMidX() > player->getMidX())
	{
		activitiAreaBegin = player->getMidX() + getGlobalValue("skeleton_player_distance");
		activityAreaEnd = activitiAreaBegin + getGlobalValue("skeleton_activity_distance");
	}
	else
	{
		activitiAreaBegin = player->getMidX() - getGlobalValue("skeleton_player_distance");
		activityAreaEnd = activitiAreaBegin - getGlobalValue("skeleton_activity_distance");
	}
}

void Skeleton::update(float dt)
{
	attackDelay.update();
	setDirectionFollowPlayer();
	switch (skeletonState)
	{
	case SKELETON_STATE_RUN:
		skeletonState = SKELETON_STATE_ATTACK;
		attackCount = getRandom(1, 3);
		break;
	case SKELETON_STATE_JUMP:

		break;
	case SKELETON_STATE_ATTACK:
		if (attackTime.atTime())
		{
			SkeletonWeapon* weapon = new SkeletonWeapon();
			weapon->setX(getX());
			weapon->setY(getY());
			attackCount--;
			if (attackCount <= 0)
			{
				skeletonState = SKELETON_STATE_RUN;
			}
		}
		break;
	default:
		break;
	}
	Enemy::update(dt);
}

Skeleton::Skeleton()
{
	attackDelay.start(getRandom(getGlobalValue("skeleton_attack_delay_min"), getGlobalValue("skeleton_attack_delay_max")));
	attackTime.setTimeDelay(200000);
}


Skeleton::~Skeleton()
{
}
