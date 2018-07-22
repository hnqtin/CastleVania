#pragma once
#include "Item.h"
class ItemSmallHeart :
	public Item
{
public:
	void onPlayerContact() override;
	ItemSmallHeart();
	~ItemSmallHeart();
};

