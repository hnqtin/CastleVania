#include "Water.h"



Water::Water()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_ITEM_WATER);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
}


Water::~Water()
{
}
