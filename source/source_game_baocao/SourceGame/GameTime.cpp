#include "GameTime.h"
#include"ConsoleLogger.h"

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
	if (deltaTime >= timeDelay)
	{
		//consoleLogger->LogLine("Time " + std::to_string(deltaTime));
		if (deltaTime > 2 * timeDelay)
		{
			deltaTime = timeDelay;
		}
		startTime = now;
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
double GameTime::getTimeDelay()
{
	return timeDelay;
}
void GameTime::setTimeDelay(double tickPerFrame)
{
	this->timeDelay = tickPerFrame;
}
double GameTime::getDeltaTime()
{
	return deltaTime;
}
void GameTime::setDeltaTime(DWORD deltaTime)
{
	this->deltaTime = deltaTime;
}
