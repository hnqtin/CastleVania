#pragma once
#include "Enemy.h"


enum BAT_STATE
{
	// khong hoat dong
	BAT_STATE_INVISIBLE,
	// simon cat vung phat hien nhung phai doi thoi gian de hien
	BAT_STATE_WAIT,
	// hien
	BAT_STATE_VISIBLE
};

enum BAT_ACTION
{
	BAT_ACTION_WAIT,
	BAT_ACTION_FLY
};

class Bat :
	public Enemy
{
	BAT_STATE batState;
	int alpha;
	Rect discoverSpace;
	Direction discoverDirection;
	DelayTime invisibleDelay;
	// dam bao trong vung chi co 1 con bat xuat hien
	// neu isActivity = true thi cho phep con bat xuat hien
	static bool isActivity;
public:
	void onInit(fstream& fs, int worldHeight) override;
	void setBatState(BAT_STATE batState);
	void update(float dt);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void restoreLocation();
	Bat();
	~Bat();
};

