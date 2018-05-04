#pragma once
#include"Texture.h"
class GameTest
{
	static GameTest* instance;

	Texture hinh;
	int xHinh, yHinh;

	int vx;
	int vy;
public:
	static GameTest* getInstance();
	void init();
	void update();
	void render();
	GameTest();
	~GameTest();
};

