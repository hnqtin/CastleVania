#pragma once
#include "BaseObject.h"
class Stair :
	public BaseObject
{
public:
	void onInit(fstream& fs, int worldHeight);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void onIntersect(MovableBox* other) override;
	void update(float dt) override;

	void playerMoveUp();
	void playerMoveDown();
	Stair();
	~Stair();
};

