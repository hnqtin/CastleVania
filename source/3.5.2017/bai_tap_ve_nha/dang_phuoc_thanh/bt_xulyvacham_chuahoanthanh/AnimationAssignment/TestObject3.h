#pragma once
#include "TestObject.h"
class TestObject3 :
	public TestObject
{
public:
	TestObject3();
	~TestObject3();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

};

