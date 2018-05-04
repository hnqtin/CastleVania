#include "EnemyObject.h"



EnemyObject::EnemyObject()
{
}


EnemyObject::~EnemyObject()
{
}

void EnemyObject::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny != 0)
			setVy(-0.1f); //****
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
}
