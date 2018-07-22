#include "ItemDagger.h"

REGISTER_OBJECT_GAME(ItemDagger, SI_IDAGGER);


void ItemDagger::onPlayerContact()
{
}

ItemDagger::ItemDagger()
{
	setAction(MISC_SPRITE_ID_ITEM_DAGGER);

}


ItemDagger::~ItemDagger()
{
}
