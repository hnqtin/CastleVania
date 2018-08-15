#pragma once
#include "AdditionalObject.h"
class Point700 :
	public AdditionalObject
{
	DelayTime disapearDelay;
public:
	void update(float dt) override;
	Point700();
	~Point700();
};

