#pragma once
#include "MovableBox.h"
#include"Sprite.h"
#include"GameTime.h"
class TestObject :
	public MovableBox
{
	GameTime delayAnimation;
public:
	int actionIndex, frameIndex;
	Sprite * sprite;
	void update();
	void render();

	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

	TestObject();
	~TestObject();
};

