#include "Game.h"
#include"KEY.h"
#include"Player.h"
#include"ScoreBar.h"

extern DWORD getKeyChar(char keyChar);

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

void Game::changeLevel(int levelIndex, int areaIndex)
{
	currentStageIndex = levelIndex;
	stages[levelIndex]->setPlayer(Player::getInstance());
	stages[currentStageIndex]->changeArea(areaIndex);
	stages[levelIndex]->resetCameraAndPlayerLocation();
	ScoreBar::getInstance()->setCurrentStageNumber(areaIndex);
	//	Camera::getInstance()->setCameraLimit(currentStage());
	Player::getInstance()->changeArea = dynamic_cast<IChangeArea*>(stages[levelIndex]);

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
	stages[0]->gate4Inf = dynamic_cast<IGate4Interface*>(this);
	stages[0]->index = 0;
	stages[0]->init
	(
		"Data/Worlds/Level1/tilesheet.png",
		"Data/Worlds/Level1/matrix.dat",
		"Data/Worlds/Level1/objects.dat",
		"Data/Worlds/Level1/quadtree.dat",
		"Data/Worlds/Level1/collision_type_collides.dat",
		"Data/Worlds/Level1/areas.dat"
	);

	stages[1] = new Stage();
	stages[1]->gate4Inf = dynamic_cast<IGate4Interface*>(this);
	stages[1]->init
	(
		"Data/Worlds/Level5/tilesheet.png",
		"Data/Worlds/Level5/matrix.dat",
		"Data/Worlds/Level5/objects.dat",
		"Data/Worlds/Level5/quadtree.dat",
		"Data/Worlds/Level5/collision_type_collides.dat",
		"Data/Worlds/Level5/areas.dat"
	);
	stages[1]->index = 1;
	changeLevel(0, 0);
}

void Game::update(float dt)
{
	if (GetAsyncKeyState(getKeyChar('q')))
		changeLevel(0, 0);
	if (GetAsyncKeyState(getKeyChar('w')))
		changeLevel(0, 1);
	if (GetAsyncKeyState(getKeyChar('e')))
		changeLevel(0, 2);
	if (GetAsyncKeyState(getKeyChar('r')))
		changeLevel(0, 3);
	if (GetAsyncKeyState(getKeyChar('t')))
		changeLevel(0, 4);

	if (GetAsyncKeyState(getKeyChar('a')))
		changeLevel(1, 0);
	if (GetAsyncKeyState(getKeyChar('s')))
		changeLevel(1, 1);
	if (GetAsyncKeyState(getKeyChar('d')))
		changeLevel(1, 2);
	if (GetAsyncKeyState(getKeyChar('f')))
		changeLevel(1, 3);
	if (GetAsyncKeyState(getKeyChar('g')))
		changeLevel(1, 4);
	if (GetAsyncKeyState(getKeyChar('h')))
		changeLevel(1, 5);

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
