#pragma once
#include"Texture.h"

#include"DelayTime.h"
#include"FpsManager.h"

class GameTest
{
	static GameTest* instance;

	Texture hinh;
	float xHinh, yHinh;

	FpsManager calculateTime;

	float vx;
	float vy;
	float ay;

	bool cancelLog;

public:
	static GameTest* getInstance();
	void init();
	void update();
	void render();
	GameTest();
	~GameTest();
};

