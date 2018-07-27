#include "BreakWall1.h"
#include"Player.h"

REGISTER_OBJECT_GAME(BreakWall1, SI_BREAK_WALL1)


void BreakWall1::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
		this->setAlive(false);
}

void BreakWall1::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	auto player = Player::getInstance();
	if (other == player)
	{
		player->preventMoveWhenCollision(collisionTime, nx, ny);
	}
}

BreakWall1::BreakWall1()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_ITEM_BREAK_WALL1);
	setDirection(getSprite()->img->direction);
}


BreakWall1::~BreakWall1()
{
}
