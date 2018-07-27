#include "WaterObj.h"
#include"Water.h"
REGISTER_OBJECT_GAME(WaterObj, SI_IWATEROBJ)

void WaterObj::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	//if (other->getCollisionType() == CT_ENEMY)
	Water* water = new Water();
	water->setX(other->getX());
	water->setY(other->getY());
	water->setVy(getGlobalValue("water_vy"));
	water->setVx(-getGlobalValue("water_vx"));

	water = new Water();
	water->setX(other->getX());
	water->setY(other->getY());
	water->setVy(getGlobalValue("water_vy"));
	water->setVx(0);

	water = new Water();
	water->setX(other->getX());
	water->setY(other->getY());
	water->setVy(getGlobalValue("water_vy"));
	water->setVx(getGlobalValue("water_vx"));
}

WaterObj::WaterObj()
{
}


WaterObj::~WaterObj()
{
}
