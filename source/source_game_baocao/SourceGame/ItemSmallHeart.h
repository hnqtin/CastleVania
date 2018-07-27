#pragma once
#include "Item.h"
class ItemSmallHeart :
	public Item
{
//private:
//	int alpha;
//	int axisX;
public:
	//void setX(float x);
	//void update(float dt) override;
	void onPlayerContact() override;
	ItemSmallHeart();
	~ItemSmallHeart();
	//void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

};

