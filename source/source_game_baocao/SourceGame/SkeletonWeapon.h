#pragma once
#include "AdditionalObject.h"
class SkeletonWeapon :
	public AdditionalObject
{
	float alpha;
	GameTime timeRotation;
public:
	void update(float dt) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime) override;
	void onIntersect(MovableBox* other) override;
	void render() override;
	SkeletonWeapon();
	~SkeletonWeapon();
};

