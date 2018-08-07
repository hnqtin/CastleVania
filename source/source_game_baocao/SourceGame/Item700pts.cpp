#include "Item700pts.h"

REGISTER_OBJECT_GAME(Item700pts, SI_I700PTS);


void Item700pts::onPlayerContact()
{
}

Item700pts::Item700pts()
{
	setAction(MISC_SPRITE_ID_ITEM_700PTS);

}


Item700pts::~Item700pts()
{
}
