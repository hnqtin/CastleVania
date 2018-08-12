#pragma once
#include<Windows.h>
class GameTime
{

	DWORD startTime;
	double timeDelay;
	double deltaTime;
public:

	DWORD getStartTime();
	void setStartTime(DWORD startTime);
	double getTimeDelay();
	void setTimeDelay(double tickPerFrame);
	double getDeltaTime();
	void setDeltaTime(DWORD deltaTime);

	GameTime(void);
	~GameTime(void);

	GameTime(DWORD tickPerFrame);
	virtual bool atTime();
	virtual void start();
};

