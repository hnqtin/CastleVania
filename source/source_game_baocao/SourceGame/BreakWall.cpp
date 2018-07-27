#include "BreakWall.h"
#include "Player.h"
REGISTER_OBJECT_GAME(BreakWall, SI_BREAK_WALL)



void BreakWall::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		this->setAlive(false);
	}
}

void BreakWall::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	auto player = Player::getInstance();
	if (other == player)
	{
		player->preventMoveWhenCollision(collisionTime, nx, ny);
	}
} 

BreakWall::BreakWall()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_ITEM_BREAK_WALL);
	setDirection(getSprite()->img->direction);
}

BreakWall::~BreakWall()
{
}
