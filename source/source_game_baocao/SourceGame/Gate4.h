#pragma once
#include "BaseObject.h"
#include"IGate4Interface.h"
class Gate4 :
	public BaseObject
{
public:
	IGate4Interface * intf;
	void onIntersect(MovableBox* other)override;
	Gate4();
	~Gate4();
};

