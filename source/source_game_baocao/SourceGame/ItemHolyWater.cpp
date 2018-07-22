#include "ItemHolyWater.h"

REGISTER_OBJECT_GAME(ItemHolyWater, SI_IHOLYWATER);

void ItemHolyWater::onPlayerContact()
{

}

ItemHolyWater::ItemHolyWater()
{
	setAction(MISC_SPRITE_ID_ITEM_HOLYWATER);

}


ItemHolyWater::~ItemHolyWater()
{
}
