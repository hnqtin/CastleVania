#include "Item1000pts.h"

REGISTER_OBJECT_GAME(Item1000pts, SI_I1000PTS);


void Item1000pts::onPlayerContact()
{
}

Item1000pts::Item1000pts()
{
	setAction(MISC_SPRITE_ID_ITEM_1000PTS);

}


Item1000pts::~Item1000pts()
{
}
