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

World * Game::currentStage()
{
	return stages[currentStageIndex];
}

void Game::nextStage()
{
	currentStageIndex++;
	Camera::getInstance()->setCameraLimit(currentStage());
	//Camera::getInstance()->set(0, 222, BACKBUFFER_WIDTH, BACKBUFFER_HEIGHT);
}

void Game::init()
{
	//Camera::getInstance()->set(0, 190, 256, 190);

	Player::getInstance()->set(getGlobalValue("player_x"),
		getGlobalValue("player_y"),
		getGlobalValue("player_width"),
		getGlobalValue("player_height")
	);

	Camera::getInstance()->set(getGlobalValue("camera_x"), 
		getGlobalValue("camera_y"), 
		BACKBUFFER_WIDTH, 
		BACKBUFFER_HEIGHT);
	Camera::getInstance()->setPlayer(Player::getInstance());
	stages = new World*[2];
	stages[0] = new World();
	//stages[0]->init(
	//	"data/worlds/stage10/tilesheet.png",
	//	"data/worlds/stage10/matrix.dat",
	//	"data/worlds/stage10/objects.dat",
	//	"data/worlds/stage10/quadtree.dat",
	//	"data/worlds/stage10/collision_type_collides.dat"
	//	);
	stages[0]->init(
		//"Data/Worlds/Stage01/tilesheet.png",
		//"Data/Worlds/Stage01/matrix.dat",
		//"Data/Worlds/Stage01/objects.dat",
		//"Data/Worlds/Stage01/quadtree.dat",
		//"Data/Worlds/Stage01/collision_type_collides.dat"
		"Data/Worlds/Stage02/tilesheet.png",
		"Data/Worlds/Stage02/matrix.dat",
		"Data/Worlds/Stage02/objects.dat",
		"Data/Worlds/Stage02/quadtree.dat",
		"Data/Worlds/Stage02/collision_type_collides.dat"
	);
	stages[0]->setPlayer(Player::getInstance());

	//stages[1] = new World();
	//stages[1]->init(
	//	"Data/Worlds/Stage12/tilesheet.png",
	//	"Data/Worlds/Stage12/matrix.dat",
	//	"Data/Worlds/Stage12/objects.dat",
	//	"Data/Worlds/Stage12/quadtree.dat",
	//	"Data/Worlds/Stage12/collision_type_collides.dat"
	//);


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
