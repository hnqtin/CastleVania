#include "GameTest.h"
#include"Config.h"


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

	vx = 1;
	vy = 1;
}
void GameTest::update()
{
	xHinh = xHinh + vx;
	yHinh = yHinh + vy;

	if (yHinh + hinh.Height >= BACKBUFFER_HEIGHT || yHinh < 0)
		vy = -vy;

	if (xHinh + hinh.Width >= BACKBUFFER_WIDTH || xHinh < 0)
		vx = -vx;

}
void GameTest::render()
{
	hinh.RenderTexture(xHinh, yHinh, 0);
}
GameTest::GameTest()
{
}


GameTest::~GameTest()
{
}
