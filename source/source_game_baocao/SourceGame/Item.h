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
public:
	ITEM_STATE itemState;
	void setState(ITEM_STATE itemState);
	void onIntersect(MovableBox* other) override;
	virtual void onPlayerContact();
	void update(float dt) override;
	Item();
	~Item();
	void restoreLocation() override;

};

