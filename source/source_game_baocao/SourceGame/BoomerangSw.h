#pragma once
#include "SubWeapon.h"
enum BOOMERANG_STATE
{
	BOOMERANG_STATE_UP,
	BOOMERANG_STATE_DOWN,
};
class BoomerangSw :
	public SubWeapon
{
	BOOMERANG_STATE boomerangState;
public:
	int xInit;
	static bool isExists;
	void onIntersect(MovableBox* other) override;
	void setNeedDelete(bool needDelete);
	void update(float dt) override;
	BoomerangSw();
	~BoomerangSw();
};

