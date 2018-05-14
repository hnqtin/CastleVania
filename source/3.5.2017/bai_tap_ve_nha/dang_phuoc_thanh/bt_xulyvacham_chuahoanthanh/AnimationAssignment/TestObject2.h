#pragma once
#include "TestObject.h"
class TestObject2 :
	public TestObject
{
public:
	TestObject2();
	~TestObject2();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

};

