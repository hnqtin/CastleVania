#include "Point700.h"



void Point700::update(float dt)
{
	disapearDelay.update();
	if (disapearDelay.isTerminated())
	{
		setNeedDelete(true);
	}
}

Point700::Point700()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_700_SCORE);
	setPhysicsEnable(false);
	setDirection(Right);
	disapearDelay.init(1000);
	disapearDelay.start();
}


Point700::~Point700()
{
}
