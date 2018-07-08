#pragma once
#include "Rect.h"
#include "ICameraLimit.h"
class Area :
	public Rect,
	public ICameraLimit
{
	int cameraX, cameraY, simonX, simonY;
public:
	void initCameraSimonLocation(int cameraX, int cameraY, int simonX, int simonY);

	int getCameraX();
	int getCameraY();
	int getSimonX();
	int getSimonY();

	int getLeft() override;
	int getRight() override;
	Area();
	~Area();
};

