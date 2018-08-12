#pragma once
#include "BaseObject.h"
#include"IChangeArea2.h"
enum GATE5_STATE
{
	GATE5_STATE_INVISIBLE,
	GATE5_STATE_OPENING,
	GATE5_STATE_OPENED,
	GATE5_STATE_CLOSING
};
enum GATE5_ACTION
{
	GATE5_ACTION_OPENING,
	GATE5_ACTION_OPENED,
	GATE5_ACTION_CLOSING
};
class Gate5 :
	public BaseObject
{
	GATE5_STATE gate5State;
	IChangeArea2* changeArea;
public:
	void setChangeArea(IChangeArea2* changeArea);
	void setState(GATE5_STATE state);
	void onInit(fstream& fs, int worldHeight) override;
	void onIntersect(MovableBox* other) override;
	void update(float dt) override;
	void restoreLocation() override;
	Gate5();
	~Gate5();
};

