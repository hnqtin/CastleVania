#pragma once
#include "SubWeaponItem.h"
class ItemDagger :
	public SubWeaponItem
{
public:
	void onPlayerContact() override;
	ItemDagger();
	~ItemDagger();
};

