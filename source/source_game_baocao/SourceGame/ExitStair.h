#pragma once
#include "BaseObject.h"
class ExitStair :
	public BaseObject
{
	bool isMoveUp;
	bool isUpRightStair;
public:
	void onInit(fstream& fs, int worldHeight) override;
	void update(float dt);
	void onIntersect(MovableBox* other) override;
	ExitStair();
	~ExitStair();
};

