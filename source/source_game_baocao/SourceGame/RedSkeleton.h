#pragma once
#include "Enemy.h"

enum RED_SKELETION
{
	RED_SKELETION_STATE_RUN,
	RED_SKELETION_STATE_DIE
};

class RedSkeleton :
	public Enemy
{
public:
	RED_SKELETION redskeletonState;
	//void update(float dt) override;
	RedSkeleton();
	~RedSkeleton();
};

