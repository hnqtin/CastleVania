#include "Game.h"
#include"KEY.h"

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

World * Game::currentStage()
{
	return stages[currentStageIndex];
}

void Game::nextStage()
{
	currentStageIndex++;
	Camera::getInstance()->setCameraLimit(currentStage());
	Camera::getInstance()->set(0, 222, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
}

void Game::init()
{
	//Camera::getInstance()->set(0, 190, 256, 190);
	Camera::getInstance()->set(0, 222, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
	stages = new World*[2];
	stages[0] = new World();
	stages[0]->init(
		"Data/Worlds/Stage10/tilesheet.png",
		"Data/Worlds/Stage10/matrix.dat",
		"Data/Worlds/Stage10/objects.dat",
		"Data/Worlds/Stage10/quadtree.dat",
		"Data/Worlds/Stage10/collision_type_collides.dat"
		);

	stages[1] = new World();
	stages[1]->init(
		"Data/Worlds/Stage12/tilesheet.png",
		"Data/Worlds/Stage12/matrix.dat",
		"Data/Worlds/Stage12/objects.dat",
		"Data/Worlds/Stage12/quadtree.dat",
		"Data/Worlds/Stage12/collision_type_collides.dat"
	);


	Camera::getInstance()->setCameraLimit(currentStage());
}

void Game::update()
{
	currentStage()->update();
}
void Game::render()
{
	currentStage()->render();
}


Game::~Game(void)
{
}