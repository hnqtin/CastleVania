#include "ItemSmallHeart.h"
#include"ScoreBar.h"

REGISTER_OBJECT_GAME (ItemSmallHeart, SI_ISMALLHEART )

void ItemSmallHeart::onPlayerContact()
{
	ScoreBar::getInstance()->increaseHeartCount(1);
}

ItemSmallHeart::ItemSmallHeart()
{
	setAction(MISC_SPRITE_ID_ITEM_SMALLHEART);
}


ItemSmallHeart::~ItemSmallHeart()
{
}
