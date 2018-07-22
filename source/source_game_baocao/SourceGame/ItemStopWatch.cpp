#include "ItemStopWatch.h"


REGISTER_OBJECT_GAME(ItemStopWatch, SI_ISTOPWATCH)

void ItemStopWatch::onPlayerContact()
{
}
ItemStopWatch::ItemStopWatch()
{
	setAction(MISC_SPRITE_ID_ITEM_STOPWATCH);
}


ItemStopWatch::~ItemStopWatch()
{
}
