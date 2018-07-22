#include "Candle.h"
REGISTER_OBJECT_GAME(Candle, SI_CANDLE)


Candle::Candle()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_CANDLE);
}

void Candle::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		this->setAlive(false);
	}

	//if (other->getCollisionType() == CT_ITEM)
	//{
	//	item = other;
	//}
}

void Candle::restoreLocation()
{
}


Candle::~Candle()
{
}
