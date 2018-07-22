#pragma once
#include "Item.h"
class ItemGoldPotion :
	public Item
{
public:
	void onPlayerContact() override;
	ItemGoldPotion();
	~ItemGoldPotion();
};

