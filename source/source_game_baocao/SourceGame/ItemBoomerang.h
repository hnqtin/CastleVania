#pragma once
#include "SubWeaponItem.h"
class ItemBoomerang :
	public SubWeaponItem
{
public:
	void onPlayerContact() override;
	ItemBoomerang();
	~ItemBoomerang();
};

