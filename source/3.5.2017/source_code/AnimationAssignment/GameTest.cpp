#include "GameTest.h"
#include"Config.h"
#include"FpsManager.h"
#include"ConsoleLogger.h"
#include"SimonPlayer.h"
#include"SpriteManager.h"
#include"CollisionTest.h"
#include"KEY.h"


GameTest * GameTest::instance = 0;
GameTest * GameTest::getInstance()
{
	if (instance == 0)
		instance = new GameTest();
	return instance;
}

void GameTest::init()
{
	//xHinh = 10;
	//yHinh = 10;

	//r = 20.0f;
	//y00 = 20;
	//hinh.Init("Data/Sprites/Simon/image.png", D3DCOLOR_XRGB(255, 255, 255));

	//vx = 0;
	//vy = 20.0f; // 10 pixel/s

	//ay = 0.0f; // 0 (pixel/s)/s

	//calculateTime.setTimePerFrame(2.0f); // 2s

	//cancelLog = false;
	//calculateTime.StartCounter_r();

	//rects = new RECT[2];

	//animationFrameIndex = 0;

	//timeDelay.setTickPerFrame(100);//100 ms

	//SetRect(&rects[0], 97, 64, 97 + 37, 64 + 37);
	//SetRect(&rects[1], 129, 69, 130 + 15, 69 + 30);

	//simonSprite = new Sprite();
	//simonSprite->ReadFromFile("Data/misc/info.simple.txt", "Data/misc/image.png");
	//actionIndex = params["actionIndex"];
	//frameIndex = 1;

	////1
	//sprite2 = SpriteManager::getSprite(SI_SIMON);
	////2
	////sprite2 = new Sprite();
	////sprite2->ReadFromFile("Data/misc/info.simple.txt", "Data/misc/image.png");
	//actionIndex2 = SIMON_PLAYER_ACTION_SIMON_JUMP;
	//frameIndex2 = 0;
	//
	//int a = 5;

	//dx = 2;
	//dy = 1;

	simonObj.setLocation(50, 50);

	simonObj.sprite = SpriteManager::getSprite(SI_SIMON);;
	simonObj.actionIndex = SIMON_PLAYER_ACTION_SIMON_JUMP;
	simonObj.frameIndex = 0;
	simonObj.setSize(16, 32);

	gach.sprite = new Sprite();
	gach.sprite->initFromSingleFrame("Data/Misc/gach.png");
	gach.setLocation(150, 150);
	gach.setSize(50, 50);
}
void GameTest::update()
{
	//// kiem tra va cham
	//// xu ly va cham
	//xHinh += dx;
	//yHinh += dy;
	//double timeGame = _FpsManager->getTimeGame();

	//if (timeDelay.atTime())
	//{
	//	sprite2->update(actionIndex2, frameIndex2);
	//}

	////switch (moveState)
	////{
	////case MOVE1:
	////	actionIndex2 = SIMON_PLAYER_ACTION_SIMON_JUMP;
	////	break;
	////case MOVE2:
	////	actionIndex2 = SIMON_PLAYER_ACTION_SIMON_ATTACK;
	////	break;
	////case MOVE3:
	////	actionIndex2 = SIMON_PLAYER_ACTION_SIMON_GO_DOWN_STAIR;
	////	break;
	////default:
	////	break;
	////}

	///*vy += ay * timeGame;
	//yHinh += vy * timeGame;*/
	////yHinh = y00 + r * sin(alpha);
	////xHinh++;
	//alpha += 0.1;
	//if (
	//	alpha >= 2 * 3.14
	//	)
	//{
	//	alpha = 0;

	//	switch (moveState)
	//	{
	//	case MOVE1:
	//		moveState = MOVE2;
	//		break;
	//	case MOVE2:
	//		moveState = MOVE3;
	//		break;
	//	case MOVE3:
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//if (calculateTime.CanCreateFrame() && !cancelLog)
	//{
	//	consoleLogger->LogLine(yHinh);
	//	cancelLog = true;
	//}

	////if (yHinh + hinh.Height >= BACKBUFFER_HEIGHT || yHinh < 0)
	////	vy = -vy;

	////if (xHinh + hinh.Width >= BACKBUFFER_WIDTH || xHinh < 0)
	////	vx = -vx;

	simonObj.update();
	int d = 2;

	if (KEY::getInstance()->isUpDown)
	{
		simonObj.setDy(d);
		simonObj.setDx(0);
	}
	else if (KEY::getInstance()->isDownDown)
	{
		simonObj.setDy(-d);
		simonObj.setDx(0);

	}
	else if (KEY::getInstance()->isLeftDown)
	{

		simonObj.setDy(0);
		simonObj.setDx(-d);
	}
	else if (KEY::getInstance()->isRightDown)
	{

		simonObj.setDy(0);
		simonObj.setDx(d);
	}
	else
	{
		simonObj.setDx(0);
		simonObj.setDy(0);
	}

	// tinh dx va dy cua 1 vat

	// kiem tra va xu ly va cham bang cach sua dx va dy
	CollisionTest::CheckCollision(&simonObj, &gach);

	// cap nhat dx va dy moi cho vat
	simonObj.setX(simonObj.getX() + simonObj.getDx());
	simonObj.setY(simonObj.getY() + simonObj.getDy());

}
void GameTest::render()
{
	//sprite2->render(xHinh, yHinh, actionIndex2, frameIndex2);

	simonObj.render();
	gach.render();
}
GameTest::GameTest()
{
	moveState = MOVE1;
}


GameTest::~GameTest()
{
}
