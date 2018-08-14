#pragma once
#include "Item.h"
#include"SubweaponType.h"

class SubWeaponItem :
	public Item
{
public:
	SUB_WEAPON_ITEM_TYPE subWeaponType;
	SubWeaponItem();
	~SubWeaponItem();
};

