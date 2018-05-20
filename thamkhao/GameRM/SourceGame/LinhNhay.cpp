#include "LinhNhay.h"

REGISTER_OBJECT_GAME(LinhNhay,SI_LINHNHAY)

void LinhNhay::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND && ny==1)
	{
		setVy(200);
	}

	if (other->getCollisionType() == CT_GROUND && nx != 0)
	{
		setVx(nx * 100);
		setDirection((Direction)nx);
	}

	Enemy::onCollision(other, nx, ny, collisionTime);
}

void LinhNhay::update()
{
	Enemy::update();
}

LinhNhay::LinhNhay()
{
	setVx(-100);
}


LinhNhay::~LinhNhay()
{
}
