#include "Weapon.h"
#include"ExplosionEffect.h"


List<Weapon*>* Weapon::weapons = 0;
List<Weapon*>* Weapon::getWeapons()
{
	if (weapons == 0)
		weapons = new List<Weapon*>();
	return weapons;
}

void Weapon::update()
{
	aliveDelay.update();
	if (aliveDelay.isTerminated())
	{
		setAlive(false);
	}
}

Weapon::Weapon()
{
	getWeapons()->_Add(this);
	setSize(42, 6);
	setCollisionType(CT_WEAPON);
	aliveDelay.init(1000);
	aliveDelay.start();
}


Weapon::~Weapon()
{
}

void Weapon::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_ENEMY)
	{
		((BaseObject*)other)->setAlive(false);
		this->setAlive(false);
		ExplosionEffect* effect = new ExplosionEffect();
		effect->setX(other->getX());
		effect->setY(other->getY());
	}
}
