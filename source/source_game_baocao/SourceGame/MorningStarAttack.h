#pragma once
#include "AdditionalObject.h"
class MorningStarAttack :
	public AdditionalObject
	
{
	DelayTime aliveDelay;
public:
	void update(float dt) override;
	void onIntersect(MovableBox* other) override;
	MorningStarAttack();
	~MorningStarAttack();
};

