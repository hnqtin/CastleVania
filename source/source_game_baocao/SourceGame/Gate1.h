#pragma once
#include "BaseObject.h"
#include"IChangeArea.h"
class Gate1 :
	public BaseObject
{
	IChangeArea * changeArea;
public:
	void setChangeArea(IChangeArea * changeArea);
	void onIntersect(MovableBox* other);
	Gate1();
	~Gate1();
};

