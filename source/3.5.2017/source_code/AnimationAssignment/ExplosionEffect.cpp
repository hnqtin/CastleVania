#include "ExplosionEffect.h"
#include"SpriteManager.h"
#include"SmallHeart.h"

List<ExplosionEffect*>* ExplosionEffect::explosionEffects = 0;
List<ExplosionEffect*>* ExplosionEffect::getExplosionEffects()
{
	if (explosionEffects == 0)
		explosionEffects = new List<ExplosionEffect*>();
	return explosionEffects;
}

void ExplosionEffect::update()
{
	timeToLive.update();
	if (timeToLive.isTerminated() && isAlive())
	{
		SmallHeart* smallHeart = new SmallHeart();
		smallHeart->setX(getX());
		smallHeart->setY(getY());
		setAlive(false);
	}
	BaseObject::update();
}

void ExplosionEffect::render()
{
	BaseObject::render();
}

ExplosionEffect::ExplosionEffect()
{
	getExplosionEffects()->_Add(this);
	setSprite(SpriteManager::getInstance()->getSprites()[SI_EXPLOSION_EFFECT]);
	timeToLive.init(1000);
	timeToLive.start();
}


ExplosionEffect::~ExplosionEffect()
{
}
