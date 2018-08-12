#include "Item.h"
#include"Player.h"
#include"MorningStar.h"
#include"MoringStarAdditional.h"
#include"GameSound.h"
extern int getRandom(int start, int end);

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
			if (MorningStar::getInstance()->getType() < MORNINGSTAR_TYPE_3)
			{
				int sx = getRandom(1, 10);
				if (sx < 8)
				{
					MoringStarAdditional* morningStarItem = new MoringStarAdditional();
					morningStarItem->setX(getX());
					morningStarItem->setY(getY());
					this->setAlive(false);
					return;
				}
			}

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
			GameSound::getInstance()->play(SOUND_OBTAIN_ITEM);
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
