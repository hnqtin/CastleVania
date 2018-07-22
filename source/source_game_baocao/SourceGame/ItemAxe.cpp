#include "ItemAxe.h"

REGISTER_OBJECT_GAME(ItemAxe, SI_IAXE)


void ItemAxe::onPlayerContact()
{
}

ItemAxe::ItemAxe()
{
	setAction(MISC_SPRITE_ID_ITEM_AXE);

}


ItemAxe::~ItemAxe()
{
}
