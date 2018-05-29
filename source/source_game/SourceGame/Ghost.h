#pragma once
#include "Enemy.h"

enum GHOST_STATE
{
	GHOST_STATE_INVISIBLE,
	GHOST_STATE_VISIBLE
};
class Ghost :
	public Enemy
{
	GHOST_STATE ghostState;
public:
	void setGhostState(GHOST_STATE ghostState);
	void onInit(fstream& fs);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update();
	void restoreLocation();
	Ghost();
	~Ghost();
};

