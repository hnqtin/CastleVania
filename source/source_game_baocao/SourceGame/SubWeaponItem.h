#pragma once
#include "Item.h"

enum SUB_WEAPON_ITEM_TYPE
{
	SUB_WEAPON_ITEM_TYPE_BOOMERANG,
	SUB_WEAPON_ITEM_TYPE_KNIFE,
};

class SubWeaponItem :
	public Item
{
public:
	SUB_WEAPON_ITEM_TYPE subWeaponType;
	SubWeaponItem();
	~SubWeaponItem();
};

