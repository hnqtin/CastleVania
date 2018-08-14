#pragma once
#include "Enemy.h"

enum BONEPILLAR_STATE
{
	BONEPILLAR_STATE_WAIT,
	BONEPILLAR_STATE_ATTACK,
};

class BonePillar :
	public Enemy
{
	DelayTime attackDelay;
	GameTime attackTime;
	int bulletNumberRemaining;
public:
	BONEPILLAR_STATE bonePillaState;
	void update(float dt) override;
	BonePillar();
	~BonePillar();
};

