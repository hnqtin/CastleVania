#include "ItemSmallHeart.h"
#include"ScoreBar.h"

//#define R 5


REGISTER_OBJECT_GAME(ItemSmallHeart, SI_ISMALLHEART)

//void ItemSmallHeart::setX(float x)
//{
//	Item::setX(x);
//	if (axisX == -1)
//	{
//		axisX = x;
//	}
//}

void ItemSmallHeart::onPlayerContact()
{
	ScoreBar::getInstance()->increaseHeartCount(1);
}


ItemSmallHeart::ItemSmallHeart()
{
	setAction(MISC_SPRITE_ID_ITEM_SMALLHEART);
	setPhysicsEnable(false);
	//	setDy(-0.5);
	//	alpha = 0;
	//	axisX = -1;
	//	setPhysicsEnable(false);
}


ItemSmallHeart::~ItemSmallHeart()
{
}

void ItemSmallHeart::update(float dt)
{
	if(isOnGround())
	{
		Item::update(dt);
		return;
	}
	Item::update(dt);
	if (itemState == ITEM_STATE_VISIBLE )
	{
		setX(getInitBox()->getX() + 10 * cos(alpha));
		setDy(-1);
		alpha += 0.1;
		if (alpha > 2 * 3.14)
		{
			alpha = 0;
		}
	}
}
//Item::update();
//}
//
//void ItemSmallHeart::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
//{
//
//	Item::onCollision(other, nx, ny, collisionTime);
//}
