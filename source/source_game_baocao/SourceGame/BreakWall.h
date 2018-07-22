#pragma once
#include "BaseObject.h"
class BreakWall :
	public BaseObject
{
public:
	void onIntersect(MovableBox * other) override;
	//void restoreLocation()override;
	BreakWall();
	~BreakWall();
};

