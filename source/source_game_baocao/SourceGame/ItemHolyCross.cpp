#include "ItemHolyCross.h"

REGISTER_OBJECT_GAME(ItemHolyCross, SI_IHOLYCROSS);

void ItemHolyCross::onPlayerContact()
{

}

ItemHolyCross::ItemHolyCross()
{
	setAction(MISC_SPRITE_ID_ITEM_HOLYCROSS);

}


ItemHolyCross::~ItemHolyCross()
{
}
