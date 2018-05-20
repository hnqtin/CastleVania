#include "FpsManager.h"

#include <windows.h>

A_FREE<FpsManager> autoFreeFpsManager = new FpsManager();

FpsManager* _FpsManager = autoFreeFpsManager;

double PCFreq = 0.0;
__int64 CounterStart = 0;

int FPS = 70;


FpsManager::FpsManager()
{
	_Fps = FPS;
	setTimePerFrame(1.0 / _Fps);
	_RealFrameCounter = 0;
	PCFreq_r = 0;
	_TimeGame = 0;
	CounterStart_r = 0;
	StartCounter_r();
}


FpsManager::~FpsManager()
{
}

bool FpsManager::CanCreateFrame()
{
	_TimeGame = GetCounter();
	if (_TimeGame >= getTimePerFrame())
	{
		if (_TimeGame > 2 * _TimePerFrame)
		{
			_TimeGame = _TimePerFrame;
		}
		StartCounter();
		_RealFrameCounter++;
		return true;
	}
	return false;
}

void FpsManager::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		consoleLogger->LogLine("QueryPerformanceFrequency failed!\n");

	PCFreq = double(li.QuadPart);
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double FpsManager::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void FpsManager::StartCounter_r()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		consoleLogger->LogLine("QueryPerformanceFrequency failed!\n");

	PCFreq_r = double(li.QuadPart);
	QueryPerformanceCounter(&li);
	CounterStart_r = li.QuadPart;
}

double FpsManager::GetCounter_r()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart_r) / PCFreq_r;
}

void FpsManager::CalculateRealFrameCounter()
{
	if (GetCounter_r() >= 1)
	{
		//consoleLogger->LogLine(_RealFrameCounter);
		_RealFrameCounter = 0;
		StartCounter_r();
	}
}


