#include "Item.h"
#include"Player.h"


void Item::setState(ITEM_STATE itemState)
{
	this->itemState = itemState;
}

void Item::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		if (itemState == ITEM_STATE::ITEM_STATE_INVISIBLE)
		{
			setState(ITEM_STATE::ITEM_STATE_VISIBLE);
			setWidth(getCurrentFrameWidth());
			setHeight(getCurrentFrameHeight());
		}
	}
	if (other == Player::getInstance())
	{
		if (itemState == ITEM_STATE::ITEM_STATE_VISIBLE)
		{
			onPlayerContact();
			this->setAlive(false);
		}
	}
}

void Item::onPlayerContact()
{
}

void Item::update(float dt)
{
	switch (itemState)
	{
	case ITEM_STATE_INVISIBLE:
		setRenderActive(false);
		setPhysicsEnable(false);
		break;
	case ITEM_STATE_VISIBLE:
		setRenderActive(true);
		setPhysicsEnable(true);
		break;
	default:
		break;
	}
	MovableObject::update(dt);
}

Item::Item()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setState(ITEM_STATE_INVISIBLE);
}


Item::~Item()
{
}

void Item::restoreLocation()
{
}
