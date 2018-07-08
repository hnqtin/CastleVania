#include "MorningStarAttack.h"
#include "ExplosionEffect.h"


void MorningStarAttack::update(float dt)
{
	aliveDelay.update();
	if (aliveDelay.isTerminated())
	{
		setNeedDelete(true);
	}
}

void MorningStarAttack::onIntersect(MovableBox * other)
{
	setNeedDelete(true);
	ExplosionEffect* effect = new ExplosionEffect();
	effect->setLocation(other->getMidX(), other->getY() - 5);
}

MorningStarAttack::MorningStarAttack()
{
	setCollisionType(COLLISION_TYPE::CT_WEAPON);
	setPhysicsEnable(false);
	setAlive(true);
	aliveDelay.init(getGlobalValue("morning_star_attack_alive_time"));
	aliveDelay.start();
}


MorningStarAttack::~MorningStarAttack()
{

}
