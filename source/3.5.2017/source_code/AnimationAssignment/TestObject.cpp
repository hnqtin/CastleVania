#include "TestObject.h"
#include"Config.h"


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
	sprite->render(getX(), BACKBUFFER_HEIGHT - getY(), actionIndex, frameIndex);
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
