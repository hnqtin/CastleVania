#include "TestObject1.h"



TestObject1::TestObject1()
{
}


TestObject1::~TestObject1()
{
}

void TestObject1::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (nx != 0)
	{
		setDx(getDx()*collisionTime);
	}
	if (ny != 0)
	{
		setDy(getDy()*collisionTime);
	}
}
