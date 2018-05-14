#pragma once
#include "TestObject.h"
class TestObject1 :
	public TestObject
{
public:
	TestObject1();
	~TestObject1();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

