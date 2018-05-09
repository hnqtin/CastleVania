#pragma once
#include"Texture.h"

#include"GameTime.h"
#include"FpsManager.h"
#include"Sprite.h"
#include"TestObject.h"

enum MOVE_STATE
{
	MOVE1,
	MOVE2,
	MOVE3
};



class GameTest
{
	static GameTest* instance;

	RECT* rects;

	Texture hinh;
	float xHinh, yHinh;
	float r, alpha, y00;

	int dx, dy;

	MOVE_STATE moveState;

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

	TestObject simonObj;
	TestObject gach;

public:
	static GameTest* getInstance();
	void init();
	void update();
	void render();
	GameTest();
	~GameTest();
};

