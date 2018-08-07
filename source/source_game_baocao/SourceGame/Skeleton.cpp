#include "Skeleton.h"
#include"Camera.h"
#include"SkeletonWeapon.h"
#include"Collision.h"

REGISTER_OBJECT_GAME(Skeleton, SI_SKELETON)
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

	if (activitiAreaBegin > activityAreaEnd)
	{
		activitiAreaBegin = activitiAreaBegin + activityAreaEnd;
		activityAreaEnd = activitiAreaBegin - activityAreaEnd;
		activitiAreaBegin = activitiAreaBegin - activityAreaEnd;
	}
}

void Skeleton::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	MovableObject::onCollision(other, nx, ny, collisionTime);
	if (other->getCollisionType() == CT_GROUND && ny == 1)
	{
		if ((getleft() < other->getleft() || getRight() > other->getRight()) && skeletonState == SKELETON_STATE_RUN)
		{
			if (getleft() < other->getleft())
			{
				setVx(-getGlobalValue("skeleton_vx_jump"));
			}
			else
			{
				setVx(getGlobalValue("skeleton_vx_jump"));
			}
			setVy(getGlobalValue("skeleton_vy_jump"));
			setIsOnGround(false);

		}
	}
}

void Skeleton::update(float dt)
{
	auto camera = Camera::getInstance();
	if (!Collision::AABBCheck(this, camera))
	{
		return;
	}
	refreshActivityArea();
	attackDelay.update();
	runDelay.update();
	setDirectionFollowPlayer();
	switch (skeletonState)
	{
	case SKELETON_STATE_RUN:
		if (isOnGround())
		{
			if (runDelay.isTerminated())
			{
				if (attackDelay.isTerminated())
				{
					skeletonState = SKELETON_STATE_ATTACK;
					attackCount = getRandom(1, 4);
					attackTime.start();
				}
				else
				{
					setVx(getRunDirection()*getGlobalValue("skeleton_vx"));
					runDelay.start();
				}
			}
		}
		break;
	case SKELETON_STATE_JUMP:

		break;
	case SKELETON_STATE_ATTACK:
		setVx(0);
		if (attackTime.atTime())
		{
			SkeletonWeapon* weapon = new SkeletonWeapon();
			weapon->setX(getX());
			weapon->setY(getY());
			weapon->setVx(getDirection()* getGlobalValue("skeletonweapon_vx"));
			weapon->setVy(getGlobalValue("skeletonweapon_vy"));
			attackCount--;
			if (attackCount <= 0)
			{
				skeletonState = SKELETON_STATE_RUN;
				attackDelay.start();
				runDelay.start();
				setVx(getRunDirection()*getGlobalValue("skeleton_vx"));
			}
		}
		break;
	default:
		break;
	}
	Enemy::update(dt);
}

int Skeleton::getRunDirection()
{
	if (getX() < activitiAreaBegin)
	{
		return 1;
	}
	if (getX() > activityAreaEnd)
	{
		return -1;
	}
	int r = getRandom(0, 1);
	if (r == 0)
		return -1;
	return 1;
}

Skeleton::Skeleton()
{
	attackDelay.start(getRandom(getGlobalValue("skeleton_attack_delay_min"), getGlobalValue("skeleton_attack_delay_max")));
	attackTime.setTimeDelay(getGlobalValue("skeleton_attack_time"));
	runDelay.init(getGlobalValue("skeleton_run_delay"));
	runDelay.start();
}


Skeleton::~Skeleton()
{
}
