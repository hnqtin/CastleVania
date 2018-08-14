#include "SubWeapon.h"
#include"ExplosionEffect.h"


void SubWeapon::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_ENEMY || other->getCollisionType() == CT_ITEM)
	{
		setNeedDelete(true);
		ExplosionEffect* effect = new ExplosionEffect();
		effect->setLocation(other->getMidX(), other->getY() - 5);
	}
}

SubWeapon::SubWeapon()
{
}


SubWeapon::~SubWeapon()
{
}
