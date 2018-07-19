#pragma once
#include "BaseObject.h"

class Candle :
	public BaseObject
{
public:
	void onIntersect(MovableBox * other) override;
	void restoreLocation()override;
	Candle();
	~Candle();
};

