#pragma once
#include "Item.h"
class ItemStopWatch :
	public Item
{
public:
	void onPlayerContact() override;
	ItemStopWatch();
	~ItemStopWatch();
};

