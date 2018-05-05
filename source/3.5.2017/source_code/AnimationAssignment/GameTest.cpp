#include "GameTest.h"
#include"Config.h"
#include"FpsManager.h"
#include"ConsoleLogger.h"
#include"SimonPlayer.h"
#include"SpriteManager.h"


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
	hinh.Init("Data/Sprites/Simon/image.png", D3DCOLOR_XRGB(255, 255, 255));

	vx = 0;
	vy = 20.0f; // 10 pixel/s

	ay = 0.0f; // 0 (pixel/s)/s

	calculateTime.setTimePerFrame(2.0f); // 2s

	cancelLog = false;
	calculateTime.StartCounter_r();

	rects = new RECT[2];

	animationFrameIndex = 0;

	timeDelay.setTickPerFrame(100);//100 ms

	SetRect(&rects[0], 97, 64, 97 + 37, 64 + 37);
	SetRect(&rects[1], 129, 69, 130 + 15, 69 + 30);

	simonSprite = new Sprite();
	simonSprite->ReadFromFile("Data/misc/info.simple.txt", "Data/misc/image.png");
	actionIndex = params["actionIndex"];
	frameIndex = 1;

	//1
	sprite2 = SpriteManager::getSprite(SI_SIMON);
	//2
	//sprite2 = new Sprite();
	//sprite2->ReadFromFile("Data/misc/info.simple.txt", "Data/misc/image.png");
	actionIndex2 = SIMON_PLAYER_ACTION_SIMON_ATTACK;
	frameIndex2 = 0;
}
void GameTest::update()
{

	double timeGame = _FpsManager->getTimeGame();

	if (timeDelay.atTime())
	{
		simonSprite->update(actionIndex, frameIndex);
		sprite2->update(actionIndex2, frameIndex2);
	}

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
	simonSprite->render((int)xHinh, (int)yHinh, actionIndex, frameIndex);
	sprite2->render(50, 50, actionIndex2, frameIndex2);
}
GameTest::GameTest()
{
}


GameTest::~GameTest()
{
}
