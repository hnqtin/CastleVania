#pragma once
#include "Item.h"
class ItemHolyCross :
	public Item
{
public:
	void onPlayerContact() override;
	ItemHolyCross();
	~ItemHolyCross();
};

