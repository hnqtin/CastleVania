#include "Item700pts.h"
#include "ScoreBar.h"
#include "Point700.h"

REGISTER_OBJECT_GAME(Item700pts, SI_I700PTS);


void Item700pts::onPlayerContact()
{
	Point700* i = new Point700();
	i->setX(getX());
	i->setY(getY());
	ScoreBar::getInstance()->increaseScore(700);

}

Item700pts::Item700pts()
{
	setAction(MISC_SPRITE_ID_ITEM_700PTS);

}


Item700pts::~Item700pts()
{
}
