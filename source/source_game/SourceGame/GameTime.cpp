#include "GameTime.h"


GameTime::GameTime(void)
{
}

void GameTime::start()
{
	startTime = GetTickCount();
}

GameTime::GameTime(DWORD tickPerFrame)
{
	this->timeDelay = tickPerFrame;
}


bool GameTime::atTime()
{

	DWORD now = GetTickCount();
	deltaTime = now - startTime;

	if(deltaTime>=timeDelay)
	{
		startTime = GetTickCount();
		return true;
	}

	return false;
}

GameTime::~GameTime(void)
{
}

DWORD GameTime::getStartTime()
{
	return startTime;
}
void GameTime::setStartTime(DWORD startTime)
{
	this->startTime = startTime;
}
DWORD GameTime::getTimeDelay()
{
	return timeDelay;
}
void GameTime::setTimeDelay(DWORD tickPerFrame)
{
	this->timeDelay = tickPerFrame;
}
DWORD GameTime::getDeltaTime()
{
	return deltaTime;
}
void GameTime::setDeltaTime(DWORD deltaTime)
{
	this->deltaTime = deltaTime;
}
