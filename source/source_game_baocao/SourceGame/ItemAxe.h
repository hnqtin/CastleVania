#pragma once
#include "Item.h"
class ItemAxe :
	public Item
{
public:
	void onPlayerContact() override;
	ItemAxe();
	~ItemAxe();
};

