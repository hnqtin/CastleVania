#pragma once
#include "Enemy.h"

enum PANTHER_STATE
{
	PANTHER_STATE_WAIT,
	PANTHER_STATE_JUMP,
	PANTHER_STATE_RUN
};

enum PANTHER_ACTION
{
	PANTHER_ACTION_WAIT,
	PANTHER_ACTION_JUMP,
	PANTHER_ACTION_RUN
};

class Panther :
	public Enemy
{
	PANTHER_STATE pantherState;
public:
	void setMeoState(PANTHER_STATE pantherState);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	void restoreLocation();
	Panther();
	~Panther();
};

