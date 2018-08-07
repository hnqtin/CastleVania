#pragma once
#include "Item.h"
class Item400pts :
	public Item
{
public:
	void onPlayerContact() override;
	Item400pts();
	~Item400pts();
};

