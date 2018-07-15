#pragma once
#include"BaseObject.h"
class GoToAction
{
	BaseObject* objectGoto;
	int xDestination, yDestination;
	bool onGoTo;
public:
	void update(float dt);
	void setGoto(BaseObject* objectGoto,int xDestination, int yDestination, int time,float dt);
	bool isOnGoTo();
	GoToAction();
	~GoToAction();
};

