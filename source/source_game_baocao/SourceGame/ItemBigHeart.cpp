#include "ItemBigHeart.h"

REGISTER_OBJECT_GAME(ItemBigHeart, SI_IBIGHEART)


void ItemBigHeart::onPlayerContact()
{
}

ItemBigHeart::ItemBigHeart()
{
	setAction(MISC_SPRITE_ID_ITEM_BIGHEART);

}


ItemBigHeart::~ItemBigHeart()
{
}
