#pragma once
#include "AdditionalObject.h"
class SkeletonWeapon :
	public AdditionalObject
{
	float alpha;
	GameTime timeRotation;
public:
	void update(float dt) override;
	void render() override;
	SkeletonWeapon();
	~SkeletonWeapon();
};

