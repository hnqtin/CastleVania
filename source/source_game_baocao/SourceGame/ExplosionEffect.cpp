#include "ExplosionEffect.h"


void ExplosionEffect::update(float dt)
{
	if (getIsLastFrame())
	{
		setNeedDelete(true);
	}
}

ExplosionEffect::ExplosionEffect()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_EXPLOSION_EFFECT);
	setCollisionType(CT_NONE);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setPhysicsEnable(false);
	setInterval(getGlobalValue("explosion_effect_interval"));
}


ExplosionEffect::~ExplosionEffect()
{
}
