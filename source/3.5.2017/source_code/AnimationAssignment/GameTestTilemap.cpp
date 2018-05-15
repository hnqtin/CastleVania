#include "GameTestTilemap.h"



GameTestTilemap * GameTestTilemap::instance = 0;
GameTestTilemap * GameTestTilemap::getInstance()
{
	if (instance == 0)
		instance = new GameTestTilemap();
	return instance;
}

void GameTestTilemap::init()
{
	t = new TileMap();
	t->init("Data/Worlds/test/tilesheet.png",
		"Data/Worlds/test/matrix.dat");

	c.set(155, 157, 249, 153);
}

void GameTestTilemap::update()
{
	//c.setX(c.getX() + 10);
}

void GameTestTilemap::render()
{
	t->render(&c);
}

GameTestTilemap::GameTestTilemap()
{
}


GameTestTilemap::~GameTestTilemap()
{
}
