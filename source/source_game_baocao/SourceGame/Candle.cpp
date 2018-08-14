#include "Candle.h"
REGISTER_OBJECT_GAME(Candle, SI_CANDLE)
#include"BaseObject.h"
#include"AdditionalObject.h"

Candle::Candle()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_CANDLE);
}

void Candle::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON || other->getCollisionType() == CT_SUB_WEAPON)
	{
		if (((BaseObject*)other)->spriteId != SI_IBOOMERANG)
		{
			((AdditionalObject*)other)->setNeedDelete(true);
		}
		GameSound::getInstance()->play(SOUND_ATTACK_ENEMY);
		this->setAlive(false);
	}
}

void Candle::restoreLocation()
{
}


Candle::~Candle()
{
}
