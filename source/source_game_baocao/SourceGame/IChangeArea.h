#pragma once
#include"Area.h"
class IChangeArea
{
public:
	virtual void resetLocation() = 0;
	virtual void changeArea(int areaIndex) = 0;
	virtual Area* getCurrentArea() = 0;
	virtual int getCurrentAreaIndex() = 0;
};