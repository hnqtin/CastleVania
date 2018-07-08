#include "linh.h"


REGISTER_OBJECT_GAME(linh, SI_LINH);
void linh::update()
{
	Enemy::update();
}

void linh::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
}

linh::linh()
{
}


linh::~linh()
{
}
