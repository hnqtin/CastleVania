#pragma once
#include "Enemy.h"
#include"Player.h"
#include"DelayTime.h"

enum BOSS_STATE
{
	BOSS_STATE_INVISIBLE,
	BOSS_STATE_WAIT,
	BOSS_STATE_MOVE_FAST,
	BOSS_STATE_MOVE_SLOW
};

enum BOSS_ACTION
{
	BOSS_ACTION_WAIT,
	BOSS_ACTION_ACTIV
};


class VampireBat :
	public Enemy
{
	BOSS_STATE bossState;
	Player* player;
	DelayTime waitDelay;

	int xo, yo, r;
	float alpha;

public:

	void setBossState(BOSS_STATE bossState);
	void update(float dt) override;

	void calculateXoYoR();

	void calculateM2(int r, int ox, int oy, int x1, int y1, float alpha, int& x2,int& y2);
	void calculateAlpha(int xo, int yo, int r, int momen,float& alpha);
	void calculateCircleFunction(int x1, int y1, int x2, int y2, int x3, int y3, int&xo, int&yo, int&r);
	VampireBat();
	~VampireBat();
};

