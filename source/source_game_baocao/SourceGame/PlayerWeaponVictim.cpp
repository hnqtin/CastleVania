#include "PlayerWeaponVictim.h"



PlayerWeaponVictim::PlayerWeaponVictim(IPlayerWeaponVictim * obj)
{
	this->obj = obj;
}

void PlayerWeaponVictim::onWeaponAttack()
{
	obj->setHealth(obj->getHealth() - 1);
	if (obj->getHealth() <= 0)
	{
		obj->setAlive(false);
	}
}


PlayerWeaponVictim::~PlayerWeaponVictim()
{
}
