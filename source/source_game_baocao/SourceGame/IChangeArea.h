#pragma once
#include"Area.h"
class IChangeArea
{
public:
	virtual void resetCameraAndPlayerLocation() = 0;
	virtual void changeArea(int areaIndex) = 0;
	virtual Area* getCurrentArea() = 0;
};