#include "Point1000.h"



void Point1000::update(float dt)
{
	disapearDelay.update();
	if (disapearDelay.isTerminated())
	{
		setNeedDelete(true);
	}
}

Point1000::Point1000()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_1000_SCORE);
	setPhysicsEnable(false);
	setDirection(Right);
	disapearDelay.init(1000);
	disapearDelay.start();
}


Point1000::~Point1000()
{
}
