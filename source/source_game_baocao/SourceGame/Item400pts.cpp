#include "Item400pts.h"
#include"ScoreBar.h"
REGISTER_OBJECT_GAME(Item400pts, SI_I400PTS);


void Item400pts::onPlayerContact()
{
	ScoreBar::getInstance()->increaseScore(400);
}

Item400pts::Item400pts()
{
	setAction(MISC_SPRITE_ID_ITEM_400PTS);

}


Item400pts::~Item400pts()
{
}
