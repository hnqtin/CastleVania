#include "ItemMorningStar.h"
#include"MorningStar.h"

REGISTER_OBJECT_GAME(ItemMorningStar, SI_IMORNING_STAR);

void ItemMorningStar::onPlayerContact()
{
	MorningStar::getInstance()->increaseType();
}

ItemMorningStar::ItemMorningStar()
{
	setAction(MISC_SPRITE_ID_ITEM_MORNING_STAR);
}


ItemMorningStar::~ItemMorningStar()
{
}
