#pragma once
#include <Windows.h>
#include "GameTime.h"

class Animation
{
public:
	// cac frames cua animation
	RECT* frames;
	// tong so frame
	int frameCount;

	Animation();
	~Animation();
	// chuyen sang frame ke tiep
	void next(int &index);
};

