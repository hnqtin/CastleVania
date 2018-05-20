#include "Game.h"
#include"KEY.h"
#include"Player.h"

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
	int backBufferWidth = getGlobalValue("backbuffer_width");
	int backBufferHeight = getGlobalValue("backbuffer_height");
	currentStageIndex++;
	Camera::getInstance()->setCameraLimit(currentStage());
	Camera::getInstance()->set(0, 222, backBufferWidth, backBufferHeight);
}

void Game::init()
{
	int backBufferWidth = getGlobalValue("backbuffer_width");
	int backBufferHeight = getGlobalValue("backbuffer_height");
	//Camera::getInstance()->set(0, 190, 256, 190);
	auto player = Player::getInstance();
	auto camera = Camera::getInstance();
	camera->setSize(backBufferWidth, backBufferHeight);
	player->setSize(getGlobalValue("player_normal_width"), getGlobalValue("player_normal_height"));
	camera->setPlayer(player);
	stages = new Stage*[1];
	stages[0] = new Stage();
	stages[0]->setCamera(camera);
	stages[0]->setPlayer(player);
	stages[0]->init(
		"Data/Stages/StageCutman/tilesheet.png",
		"Data/Stages/StageCutman/matrix.dat",
		"Data/Stages/StageCutman/objects.dat",
		"Data/Stages/StageCutman/quadtree.dat",
		"Data/Stages/StageCutman/locations.dat",
		"Data/Stages/StageCutman/collision_type_collides.dat"
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
