#include "Gate5.h"

REGISTER_OBJECT_GAME(Gate5, SI_GATE_5)

void Gate5::setChangeArea(IChangeArea2 * changeArea)
{
	this->changeArea = changeArea;
}

void Gate5::setState(GATE5_STATE state)
{
	this->gate5State = state;
}

void Gate5::onInit(fstream & fs, int worldHeight)
{
	getInitBox()->setWidth(getCurrentFrameWidth());
	getInitBox()->setHeight(getCurrentFrameHeight());
	getInitBox()->setY(getY() + 32);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setY(getInitBox()->getY());
}

void Gate5::onIntersect(MovableBox * other)
{
	if (other->getleft()<getleft())
		changeArea->setGate5(this);
}

void Gate5::update(float dt)
{
	switch (gate5State)
	{
	case GATE5_STATE_INVISIBLE:
		setRenderActive(false);
		break;
	case GATE5_STATE_OPENING:
		setRenderActive(true);
		setAction(GATE5_ACTION_OPENING);
		break;
	case GATE5_STATE_OPENED:
		setRenderActive(true);
		setAction(GATE5_ACTION_OPENED);
		break;
	case GATE5_STATE_CLOSING:
		setRenderActive(true);
		setAction(GATE5_ACTION_CLOSING);
		break;
	default:
		break;
	}
}

void Gate5::restoreLocation()
{
}

Gate5::Gate5()
{
	gate5State = GATE5_STATE_INVISIBLE;
}


Gate5::~Gate5()
{
}
