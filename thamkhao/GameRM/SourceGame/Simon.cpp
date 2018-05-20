#include "Simon.h"

REGISTER_OBJECT_GAME(Simon, SI_SIMON);

void Simon::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND && nx!= 0)
	{
		setVx(nx * 100);
		setDirection((Direction)nx);
	}
	Enemy::onCollision(other, nx, ny, collisionTime);
}

void Simon::update()
{
	//roi xuong
	Enemy::update();
	
}

Simon::Simon()
{
	setVx(-100);
}


Simon::~Simon()
{
}
