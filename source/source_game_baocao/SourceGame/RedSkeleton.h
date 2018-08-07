#pragma once
#include "Enemy.h"


enum RED_SKELETON_ACTION
{
	RED_SKELETON_ACTION_RUN,
	RED_SKELETON_ACTION_DYING,
	RED_SKELETON_ACTION_DIE,
	RED_SKELETON_ACTION_RESTORE
};

enum RED_SKELETION_STATE
{
	RED_SKELETON_STATE_RUN,
	RED_SKELETON_STATE_DYING,
	RED_SKELETON_STATE_DIE,
	RED_SKELETON_STATE_RESTORE
};

class RedSkeleton :
	public Enemy
{
	DelayTime dieDelay;
public:
	RED_SKELETION_STATE redskeletonState;
	void update(float dt) override;
	void onContactWeapon() override;
	void onIntersect(MovableBox* other) override;
	RedSkeleton();
	~RedSkeleton();
};

