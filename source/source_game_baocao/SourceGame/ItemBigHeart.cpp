#include "ItemBigHeart.h"
#include"ScoreBar.h"

REGISTER_OBJECT_GAME(ItemBigHeart, SI_IBIGHEART)


void ItemBigHeart::onPlayerContact()
{
	ScoreBar::getInstance()->increaseHeartCount(10);
}

ItemBigHeart::ItemBigHeart()
{
	setAction(MISC_SPRITE_ID_ITEM_BIGHEART);

}


ItemBigHeart::~ItemBigHeart()
{
}
