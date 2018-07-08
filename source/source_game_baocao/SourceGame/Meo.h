#pragma once
#include "Enemy.h"

enum MEO_STATE
{
	MEO_STATE_WAIT,
	MEO_STATE_JUMP,
	MEO_STATE_RUN
};

enum MEO_ACTION
{
	MEO_ACTION_WAIT,
	MEO_ACTION_JUMP,
	MEO_ACTION_RUN
};

class Meo :
	public Enemy
{
	MEO_STATE meoState;
public:
	void setMeoState(MEO_STATE meoState);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	void restoreLocation();
	Meo();
	~Meo();
};

