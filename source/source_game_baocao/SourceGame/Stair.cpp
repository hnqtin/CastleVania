#include "Stair.h"
REGISTER_OBJECT_GAME(Stair,SI_STAIR)
#include"Player.h"

void Stair::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (ny == 1)
	{
		other->preventMoveWhenCollision(collisionTime, nx, ny);
		Player::getInstance()->setIsOnGround(true);
		Player::getInstance()->setVy(-10);
	}
}

Stair::Stair()
{

}


Stair::~Stair()
{
}
