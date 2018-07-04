#pragma once
#include<Windows.h>
class GameTime
{

	DWORD startTime;
	DWORD timeDelay;
	DWORD deltaTime;
public:

	DWORD getStartTime();
	void setStartTime(DWORD startTime);
	DWORD getTimeDelay();
	void setTimeDelay(DWORD tickPerFrame);
	DWORD getDeltaTime();
	void setDeltaTime(DWORD deltaTime);

	GameTime(void);
	~GameTime(void);

	GameTime(DWORD tickPerFrame);
	virtual bool atTime();
	virtual void start();
};

