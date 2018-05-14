#include "TestObject2.h"



TestObject2::TestObject2()
{
}


TestObject2::~TestObject2()
{
}

void TestObject2::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (ny == 1)
	{
		setVy(0.4);
	}
}
