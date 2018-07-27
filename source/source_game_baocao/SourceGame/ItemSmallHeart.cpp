#include "ItemSmallHeart.h"
#include"ScoreBar.h"
//#define R 5


REGISTER_OBJECT_GAME (ItemSmallHeart, SI_ISMALLHEART )

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
//	setDy(-0.5);
//	alpha = 0;
//	axisX = -1;
//	setPhysicsEnable(false);
}


ItemSmallHeart::~ItemSmallHeart()
{
}

//void ItemSmallHeart::update(float dt)
//{
//	if (getDy() != 0)
//	{
//		alpha = (alpha + 5) % 360;
//		moveY(getDy());
//		axisX = -1;
//		setX( axisX + R * sin(alpha * 0.017444));
//	}
//Item::update();
//}
//
//void ItemSmallHeart::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
//{
//
//	Item::onCollision(other, nx, ny, collisionTime);
//}
