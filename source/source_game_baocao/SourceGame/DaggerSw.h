#pragma once
#include"SubWeapon.h"



class DaggerSw :
	public SubWeapon
{
public:
	static bool isExists;
	void update(float dt) override;
	DaggerSw();
	~DaggerSw();
};

