#pragma once
#include "AdditionalObject.h"
class SubWeapon :
	public AdditionalObject
{
public:
	void onIntersect(MovableBox* other) override;
	SubWeapon();
	~SubWeapon();
};

