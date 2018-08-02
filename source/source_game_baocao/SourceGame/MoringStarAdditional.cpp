#include "MoringStarAdditional.h"
#include"Player.h"
#include"MorningStar.h"

MoringStarAdditional::MoringStarAdditional()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_ITEM_MORNING_STAR);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setCollisionType(CT_ITEM);
}



void MoringStarAdditional::onIntersect(MovableBox * other)
{
	if (other == Player::getInstance() && this->isAlive())
	{
		MorningStar::getInstance()->increaseType();
		Player::getInstance()->obtainMorningStarDelay.start();
		this->setNeedDelete(true);
		this->setAlive(false);
	}
}


MoringStarAdditional::~MoringStarAdditional()
{
}
