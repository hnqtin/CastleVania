#pragma once
#include "Enemy.h"

enum FLEAMAN_ACTION
{
	FLEAMAN_ACTION_WAIT,
	FLEAMAN_ACTION_RUN
};

enum FLEAMAN_STATE
{
	FLEAMAN_STATE_WAIT,
	FLEAMAN_STATE_RUN,
	FLEAMAN_STATE_JUMP,
};

class Fleaman :
	public Enemy
{
	FLEAMAN_STATE fleamanState;
	DelayTime waitDelay;
public:
	FLEAMAN_STATE chooseState();
	void update(float dt) override;
	void restoreLocation() override;
	Fleaman();
	~Fleaman();
};

