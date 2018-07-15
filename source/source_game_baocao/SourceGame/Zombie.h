#pragma once
#include "Enemy.h"

enum ZOMBIE_STATE
{
	ZOMBIE_STATE_INVISIBLE,
	ZOMBIE_STATE_VISIBLE
};
class Zombie :
	public Enemy
{
	ZOMBIE_STATE zombieState;
public:
	void setZombieState(ZOMBIE_STATE zombieState);
	void onInit(fstream& fs, int worldHeight) override;
	void onIntersect(MovableBox* other) override;
	void setDx(float dx) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void update(float dt);
	void restoreLocation();
	void onContactPlayer() override;
	Zombie();
	~Zombie();
};

