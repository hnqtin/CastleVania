#pragma once
#include "Item.h"
class ItemBigHeart :
	public Item
{
public:
	void onPlayerContact() override;
	ItemBigHeart();
	~ItemBigHeart();
};

