#include "EagleEnemy.h"



void EagleEnemy::update()
{
	BaseObject::update();
}

bool EagleEnemy::canCollision()
{
	return false;
}

EagleEnemy::EagleEnemy()
{
	setPhysicsEnable(false);
	setDx(-3);
	setDirection(Left);
}


EagleEnemy::~EagleEnemy()
{
}
