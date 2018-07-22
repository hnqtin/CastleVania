#include "ItemGoldPotion.h"

REGISTER_OBJECT_GAME(ItemGoldPotion, SI_IGOLDPOTION);

void ItemGoldPotion::onPlayerContact()
{

}

ItemGoldPotion::ItemGoldPotion()
{
	setAction(MISC_SPRITE_ID_ITEM_GOLDPOTION);

}


ItemGoldPotion::~ItemGoldPotion()
{
}
