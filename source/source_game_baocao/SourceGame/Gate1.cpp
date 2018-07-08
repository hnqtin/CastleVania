#include "Gate1.h"
REGISTER_OBJECT_GAME(Gate1,SI_GATE_1)
#include"World.h"

void Gate1::setChangeArea(IChangeArea * changeArea)
{
	this->changeArea = changeArea;
}

void Gate1::onIntersect(MovableBox * other)
{
	changeArea->changeArea(1);
	changeArea->resetCameraAndPlayerLocation();
}

Gate1::Gate1()
{
}


Gate1::~Gate1()
{
}
