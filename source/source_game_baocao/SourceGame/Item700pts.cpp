#include "Item700pts.h"
#include "ScoreBar.h"

REGISTER_OBJECT_GAME(Item700pts, SI_I700PTS);


void Item700pts::onPlayerContact()
{
	ScoreBar::getInstance()->increaseScore(700);

}

Item700pts::Item700pts()
{
	setAction(MISC_SPRITE_ID_ITEM_700PTS);

}


Item700pts::~Item700pts()
{
}
