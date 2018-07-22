#pragma once
#include "Item.h"
class ItemDagger :
	public Item
{
public:
	void onPlayerContact() override;
	ItemDagger();
	~ItemDagger();
};

