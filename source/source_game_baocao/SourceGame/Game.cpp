#include "Game.h"
#include"KEY.h"
#include"Player.h"
#include"ScoreBar.h"

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

Stage * Game::currentStage()
{
	return stages[currentStageIndex];
}

void Game::nextStage()
{
	currentStageIndex++;
	Camera::getInstance()->setCameraLimit(currentStage());
}

void Game::init()
{
	Player::getInstance()->set(getGlobalValue("player_x"),
		getGlobalValue("player_y"),
		getGlobalValue("player_width"),
		getGlobalValue("player_height")
	);

	Camera::getInstance()->set(getGlobalValue("camera_x"), 
		getGlobalValue("camera_y"), 
		getGlobalValue("backbuffer_width"), 
		getGlobalValue("backbuffer_height"));
	Camera::getInstance()->setPlayer(Player::getInstance());
	stages = new Stage*[2];
	stages[0] = new Stage();

	stages[0]->init
	(
		"Data/Worlds/Level1/tilesheet.png",
		"Data/Worlds/Level1/matrix.dat",
		"Data/Worlds/Level1/objects.dat",
		"Data/Worlds/Level1/quadtree.dat",
		"Data/Worlds/Level1/collision_type_collides.dat",
		"Data/Worlds/Level1/areas.dat"		
	);

	stages[0]->setPlayer(Player::getInstance());
	stages[0]->changeArea(2);
	stages[0]->resetCameraAndPlayerLocation();

	
}

void Game::update(float dt)
{
	currentStage()->update(dt);
	ScoreBar::getInstance()->update();
}
void Game::render()
{
	currentStage()->render();
	ScoreBar::getInstance()->render();
}


Game::~Game(void)
{
}
