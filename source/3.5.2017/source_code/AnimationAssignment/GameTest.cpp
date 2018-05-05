#include "GameTest.h"
#include"Config.h"
#include"FpsManager.h"
#include"ConsoleLogger.h"

GameTest * GameTest::instance = 0;
GameTest * GameTest::getInstance()
{
	if (instance == 0)
		instance = new GameTest();
	return instance;
}

void GameTest::init()
{
	xHinh = 10;
	yHinh = 10;
	hinh.Init("Data/Misc/bong.png", D3DCOLOR_XRGB(255, 255, 255));

	vx = 0;
	vy = 10.0f; // 10 pixel/s

	ay = 0.0f; // 0 (pixel/s)/s

	calculateTime.setTimePerFrame(2.0f); // 2s

	cancelLog = false;
	calculateTime.StartCounter_r();
}
void GameTest::update()
{
	double timeGame = _FpsManager->getTimeGame();


	vy += ay * timeGame;
	yHinh += vy * timeGame;

	if (calculateTime.CanCreateFrame() && !cancelLog)
	{
		consoleLogger->LogLine(yHinh);
		cancelLog = true;
	}

	//if (yHinh + hinh.Height >= BACKBUFFER_HEIGHT || yHinh < 0)
	//	vy = -vy;

	//if (xHinh + hinh.Width >= BACKBUFFER_WIDTH || xHinh < 0)
	//	vx = -vx;

}
void GameTest::render()
{
	hinh.RenderTexture((int)xHinh, (int)yHinh, 0);
}
GameTest::GameTest()
{
}


GameTest::~GameTest()
{
}
