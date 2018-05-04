#pragma once
#include"Item.h"
class SmallHeart : public Item
{
public:
	SmallHeart();
	~SmallHeart();
	void update();
	void onIntersect(MovableBox* other);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

