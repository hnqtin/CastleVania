#pragma once
#include "MovableObject.h"

enum ITEM_STATE
{
	ITEM_STATE_INVISIBLE,
	ITEM_STATE_VISIBLE,
};

class Item :
	public MovableObject
{
	ITEM_STATE itemState;
public:
	void setState(ITEM_STATE itemState);
	void onIntersect(MovableBox* other) override;
	virtual void onPlayerContact();
	void update(float dt) override;
	Item();
	~Item();
	void restoreLocation() override;

};

