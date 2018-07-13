#include "Area.h"



void Area::initCameraSimonLocation(int cameraX, int cameraY, int simonX, int simonY)
{
	this->cameraX = cameraX;
	this->cameraY = cameraY;
	this->simonX = simonX;
	this->simonY = simonY;
}


int Area::getCameraX()
{
	return cameraX;
}
int Area::getCameraY()
{
	return cameraY;
}
int Area::getSimonX()
{
	return simonX;
}
int Area::getSimonY()
{
	return simonY;
}

int Area::getLeft()
{
	return Rect::getleft()+1;
}

int Area::getRight()
{
	return Rect::getRight()-1;
}

Area::Area()
{
}


Area::~Area()
{
}
