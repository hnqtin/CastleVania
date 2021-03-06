#include<Windows.h>
#include"WindowGame.h"
#include"DirectXTool.h"
#include"Texture.h"
#include"Game.h"
#include"ConsoleLogger.h"
#include"GameSound.h"
#include"KEY.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));

	GameTime timeRenderFrame;
	timeRenderFrame.setTimeDelay(1000.0f / getGlobalValue("game_fps"));

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	GameSound::getInstance()->initialize(WindowGame::getInstance()->getHandleWindow());
	GameSound::getInstance()->play(SOUND_BACKGROUND, true, true);
	Game::getInstance()->init();

	while (msg.message != WM_QUIT)
	{
		if (timeRenderFrame.atTime())
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			KEY::getInstance()->update();
			float time = timeRenderFrame.getDeltaTime() / 1000.0f;
			Game::getInstance()->update(time);
			DirectXTool::getInstance()->BeginGraphics();//bat dau ve len backbuffer
			Game::getInstance()->render();
			DirectXTool::getInstance()->EndGraphics();// ket thuc ve len backbuffer
			DirectXTool::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
		}

	}

	return nCmdShow;
}
