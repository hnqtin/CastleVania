#pragma once
#include "Enemy.h"

enum SKELETON_STATE
{
	SKELETON_STATE_RUN,
	SKELETON_STATE_JUMP,
	SKELETON_STATE_ATTACK
};

class Skeleton :
	public Enemy
{
	SKELETON_STATE skeletonState;

	int activitiAreaBegin, activityAreaEnd;
	void refreshActivityArea();
	DelayTime attackDelay;
	GameTime attackTime;

	int attackCount;
public:
	void update(float dt) override;
	Skeleton();
	~Skeleton();
};

