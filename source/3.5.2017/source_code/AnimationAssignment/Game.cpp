#include "Game.h"
#include"KEY.h"
#include"SimonPlayer.h"

Game::Game(void)
{
}
Game* Game::instance = 0;

Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

void Game::init()
{
	Camera::getInstance()->set(0, 190, 256, 190);
	SimonPlayer::getInstance()->set(100, 78, 16, 30);
	world = new World();
	world->init("Data/Worlds/stage10/tilesheet.png",
		"Data/Worlds/stage10/matrix.dat",
		"Data/Worlds/stage10/objects.dat",
		"Data/Worlds/stage10/quadtree.dat",
		"Data/Worlds/stage10/collision_type_collides.dat"
		);
}

void Game::update()
{
	world->update();
}
void Game::render()
{
	world->render();
}


Game::~Game(void)
{
}
