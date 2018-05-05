#pragma once
#include"Texture.h"

#include"GameTime.h"
#include"FpsManager.h"
#include"Sprite.h"

class GameTest
{
	static GameTest* instance;

	RECT* rects;

	Texture hinh;
	float xHinh, yHinh;

	FpsManager calculateTime;

	int animationFrameIndex;

	GameTime timeDelay;

	float vx;
	float vy;
	float ay;

	bool cancelLog;

	int actionIndex;
	int frameIndex;
	Sprite* simonSprite;

	Sprite* sprite2;
	int actionIndex2;
	int frameIndex2;

public:
	static GameTest* getInstance();
	void init();
	void update();
	void render();
	GameTest();
	~GameTest();
};

