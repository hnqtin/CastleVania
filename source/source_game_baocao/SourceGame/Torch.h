#pragma once
#include "BaseObject.h"
class Torch :
	public BaseObject
{
public:
	void update(float dt);
	void render();
	void onIntersect(MovableBox* other) override;
	void restoreLocation() override;
	Torch();
	~Torch();
};

