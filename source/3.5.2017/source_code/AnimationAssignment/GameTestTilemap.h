#pragma once
#include"TileMap.h"
class GameTestTilemap
{
	static GameTestTilemap* instance;
public:
	static GameTestTilemap* getInstance();
	TileMap* t;
	Camera c;
	void init();
	void update();
	void render();
	GameTestTilemap();
	~GameTestTilemap();
};

