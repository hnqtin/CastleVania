#include "Point400.h"


void Point400::update(float dt)
{
	disapearDelay.update();
	if (disapearDelay.isTerminated())
	{
		setNeedDelete(true);
	}
}

Point400::Point400()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_400_SCORE);
	setPhysicsEnable(false);
	setDirection(Right);
	disapearDelay.init(1000);
	disapearDelay.start();
}


Point400::~Point400()
{
}
