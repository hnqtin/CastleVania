#pragma once
class IChangeArea
{
public:
	virtual void resetCameraAndPlayerLocation() = 0;
	virtual void changeArea(int areaIndex) = 0;
};