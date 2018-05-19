#include<Windows.h>
#include"Form.h"
#include"DirectXTool.h"
#include"Texture.h"
#include"Game.h"
#include"KEY.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include"FpsManager.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Form::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));
	CKeyboard::Create(hInstance, Form::getInstance()->getHandleWindow());

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));


	Game::getInstance()->init();

	while (msg.message != WM_QUIT)
	{
		if (_FpsManager->CanCreateFrame())
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			CKeyboard::getInstance()->PollKeyboard();
			CKeyboard::getInstance()->UpdateKeyboard();
			KEY::getInstance()->update();
			Game::getInstance()->update();
			DirectXTool::getInstance()->BeginGraphics();//bat dau ve len backbuffer
			Game::getInstance()->render();
			DirectXTool::getInstance()->EndGraphics();// ket thuc ve len backbuffer
			DirectXTool::getInstance()->PresentBackBuffer();// ve backbuffer len man hinh
			_FpsManager->CalculateRealFrameCounter();
			auto timeSleep = (_FpsManager->getTimePerFrame() - _FpsManager->GetCounter());
			if (timeSleep > 0)
			{
				std::this_thread::sleep_for(std::chrono::nanoseconds((long)(timeSleep*1000000000+1)));
			}
		}

	}


	return nCmdShow;
}
