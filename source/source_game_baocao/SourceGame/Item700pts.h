#pragma once
#include "Item.h"
class Item700pts :
	public Item
{
public:
	void onPlayerContact() override;
	Item700pts();
	~Item700pts();
};

