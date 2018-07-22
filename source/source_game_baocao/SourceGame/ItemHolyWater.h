#pragma once
#include "Item.h"
class ItemHolyWater :
	public Item
{
public:
	void onPlayerContact() override;
	ItemHolyWater();
	~ItemHolyWater();
};

