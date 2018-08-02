#pragma once
#include "Enemy.h"
#include"Player.h"
#include"DelayTime.h"
#include"IChangeArea.h"
#include"IBoss.h"

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
	public Enemy,
	public IBoss
{
	BOSS_STATE bossState;
	Player* player;
	DelayTime waitDelay;
	DelayTime moveFastDelay;
	DelayTime moveSlowDelay;
	float xDes, yDes;
	IChangeArea* changeArea;
public:
	void setChangeArea(IChangeArea* changeArea);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void setBossState(BOSS_STATE bossState);
	void update(float dt) override;
	void calculateOtherPoint();

	void onDecreaseHealth();

	void restore();

	void preventGoOutsideCamera();

	VampireBat();
	~VampireBat();
};

