#include "TestObject3.h"



TestObject3::TestObject3()
{
}


TestObject3::~TestObject3()
{
}

void TestObject3::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	actionIndex = 6;

	if (nx != 0)
	{
		setDx(getDx()*collisionTime);
	}
	if (ny != 0)
	{
		setDy(getDy()*collisionTime);
	}
}
