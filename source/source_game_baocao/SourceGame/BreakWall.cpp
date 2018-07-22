#include "BreakWall.h"



BreakWall::BreakWall()
{
}

void BreakWall::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		this->setAlive(false);
	}
}
BreakWall::~BreakWall()
{
}
