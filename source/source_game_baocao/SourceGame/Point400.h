#pragma once
#include "AdditionalObject.h"
class Point400 :
	public AdditionalObject
{
	DelayTime disapearDelay;
public:
	void update(float dt) override;
	Point400();
	~Point400();
};

