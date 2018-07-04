#pragma once
#include "Enemy.h"

enum MERMAN_STATE
{
	MERMAN_STATE_INVISIBLE,
	MERMAN_STATE_JUMP,
	MERMAN_STATE_RUN,
	MERMAN_STATE_ATTACK
};
enum MERMAN_ACTION
{
	MERMAN_ACTION_JUMP,
	MERMAN_ACTION_RUN,
	MERMAN_ACTION_SHOOT
};

class Merman :
	
	public Enemy
{
	bool isVisible;
	MERMAN_STATE mermanState;
	MERMAN_ACTION mermanAction;

	DelayTime runDelay;
	DelayTime attackDelay;

public:
	void update(float dt);
	void setMermanState(MERMAN_STATE mermanState);
	MERMAN_STATE getMermanState();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	Merman();
	~Merman();
};

