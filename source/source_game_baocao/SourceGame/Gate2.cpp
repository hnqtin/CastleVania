#include "Gate2.h"

REGISTER_OBJECT_GAME(Gate2, SI_GATE2)

void Gate2::setChangeArea(IChangeArea2 * changeArea)
{
	this->changeArea = changeArea;
}

void Gate2::setState(GATE2_STATE state)
{
	this->gate2State = state;
}

void Gate2::onInit(fstream & fs, int worldHeight)
{
	getInitBox()->setWidth(getCurrentFrameWidth());
	getInitBox()->setHeight(getCurrentFrameHeight());
	getInitBox()->setY(getY() + 32);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setY(getInitBox()->getY());
}

void Gate2::onIntersect(MovableBox * other)
{
	changeArea->setGate2(this);
}

void Gate2::update(float dt)
{
	switch (gate2State)
	{
	case GATE2_STATE_INVISIBLE:
		setRenderActive(false);
		break;
	case GATE2_STATE_OPENING:
		setRenderActive(true);
		setAction(GATE2_ACTION_OPENING);
		break;
	case GATE2_STATE_OPENED:
		setRenderActive(true);
		setAction(GATE2_ACTION_OPENED);
		break;
	case GATE2_STATE_CLOSING:
		setRenderActive(true);
		setAction(GATE2_ACTION_CLOSING);
		break;
	default:
		break;
	}
}

Gate2::Gate2()
{
	gate2State = GATE2_STATE_INVISIBLE;
}


Gate2::~Gate2()
{
}
