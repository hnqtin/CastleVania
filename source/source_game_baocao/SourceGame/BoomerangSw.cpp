#include "BoomerangSw.h"
#include"Player.h"

bool BoomerangSw::isExists = false;

void BoomerangSw::onIntersect(MovableBox * other)
{
	if (other == Player::getInstance() && boomerangState== BOOMERANG_STATE_DOWN)
	{
		this->setNeedDelete(true);
	}
}

void BoomerangSw::setNeedDelete(bool needDelete)
{
	if (needDelete)
	{
		isExists = false;
	}
	AdditionalObject::setNeedDelete(needDelete);
}

void BoomerangSw::update(float dt)
{
	switch (boomerangState)
	{
	case BOOMERANG_STATE_UP:
		setDx(getDirection()*getGlobalValue("boomerang_vx"));
		if (abs(getX() - xInit) > getGlobalValue("boomerang_distance"))
		{
			boomerangState = BOOMERANG_STATE_DOWN;
		}
		break;
	case BOOMERANG_STATE_DOWN:
		setDx(-getDirection()*getGlobalValue("boomerang_vx"));
		break;
	default:
		break;
	}
	SubWeapon::update(dt);
}

BoomerangSw::BoomerangSw()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_BOOMERANG);
	isExists = true;
	setPhysicsEnable(false);
	boomerangState = BOOMERANG_STATE_UP;
	setCollisionType(CT_WEAPON);
}


BoomerangSw::~BoomerangSw()
{
}
