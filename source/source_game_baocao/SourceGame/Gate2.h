#pragma once
#include "BaseObject.h"
#include"IChangeArea2.h"
enum GATE2_STATE
{
	GATE2_STATE_INVISIBLE,
	GATE2_STATE_OPENING,
	GATE2_STATE_OPENED,
	GATE2_STATE_CLOSING
};
enum GATE2_ACTION
{
	GATE2_ACTION_OPENING,
	GATE2_ACTION_OPENED,
	GATE2_ACTION_CLOSING
};
class Gate2 :
	public BaseObject
{
	GATE2_STATE gate2State;
	IChangeArea2* changeArea;
public:
	void setChangeArea(IChangeArea2* changeArea);
	void setState(GATE2_STATE state);
	void onInit(fstream& fs, int worldHeight) override;
	void onIntersect(MovableBox* other) override;
	void update(float dt) override;
	Gate2();
	~Gate2();
};

