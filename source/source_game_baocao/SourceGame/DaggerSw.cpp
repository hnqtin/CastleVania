#include "DaggerSw.h"

bool DaggerSw::isExists = false;


void DaggerSw::update(float dt)
{
	setDx(getGlobalValue("dagger_dx")*getDirection());
	SubWeapon::update(dt);
}

DaggerSw::DaggerSw()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_ITEM_DAGGER);
	isExists = true;
	setCollisionType(CT_SUB_WEAPON);
	setPhysicsEnable(false);
}


DaggerSw::~DaggerSw()
{
	isExists = false;
}
