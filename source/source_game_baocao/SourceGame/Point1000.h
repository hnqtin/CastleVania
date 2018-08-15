#pragma once
#include "AdditionalObject.h"
class Point1000 :
	public AdditionalObject
{
	DelayTime disapearDelay;
public:
	void update(float dt) override;
	Point1000();
	~Point1000();
};

