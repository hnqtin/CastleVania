#include "GoToAction.h"
#include"ConsoleLogger.h"
#include<string>
using namespace std;

void GoToAction::update(float dt)
{
	if (!onGoTo)
		return;
	float objectX = objectGoto->getX();
	float dx = objectGoto->getDx();
	float objectY = objectGoto->getY();
	float dy = objectGoto->getDy();

	if ((objectX + dx >= xDestination && dx > 0) ||
		(objectX + dx <= xDestination && dx < 0) ||
		(objectY + dy >= yDestination && dy > 0) ||
		(objectY + dy <= yDestination && dy < 0))
	{
		//objectGoto->setX(xDestination);
		objectGoto->setDx(0);
		objectGoto->setVx(0);
		//objectGoto->setY(yDestination);
		objectGoto->setLocation(xDestination, yDestination);
		objectGoto->setDy(0);
		objectGoto->setVy(0);
		onGoTo = false;

	}
}

void GoToAction::setGoto(BaseObject * objectGoto, int xDestination, int yDestination, int time, float dt)
{
	this->objectGoto = objectGoto;
	this->xDestination = xDestination;
	this->yDestination = yDestination;
	float x = (xDestination - objectGoto->getX());
	float y = (yDestination - objectGoto->getY());
	objectGoto->setDx(dt * (x / (time / 1000.0f)));
	objectGoto->setDy(dt * (y / (time / 1000.0f)));
	onGoTo = true;
	//consoleLogger->LogLine((string)"destination x: " + std::to_string(xDestination) + "destination y: " + to_string(yDestination));
}

bool GoToAction::isOnGoTo()
{
	return onGoTo;
}

GoToAction::GoToAction()
{
}


GoToAction::~GoToAction()
{
}
