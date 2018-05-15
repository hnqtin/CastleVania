#include "TestObject.h"
#include"Config.h"
#include"Camera.h"


TestObject::TestObject()
{
	delayAnimation.setTickPerFrame(100);
}


TestObject::~TestObject()
{
}

void TestObject::update()
{
	if (delayAnimation.atTime())
	{
		sprite->update(actionIndex, frameIndex);
	}
}
void TestObject::render()
{
	int xV = 0, yV = 0;
	Camera::getInstance()->getWorldToViewLocation(getX(), getY(), xV, yV);
	sprite->render(xV, yV, actionIndex, frameIndex);
}

void TestObject::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
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
