#pragma once
#include "Item.h"
class ItemMorningStar :
	public Item
{
public:
	void onPlayerContact() override;
	ItemMorningStar();
	~ItemMorningStar();
};

