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

	DelayTime runDelay;

	int attackCount;
public:
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update(float dt) override;
	int getRunDirection();
	Skeleton();
	~Skeleton();
};

