#pragma once
#include "BaseObject.h"
#include"IChangeArea.h"
class Gate3 :
	public BaseObject
{
	int playerX, playerY, nextArea;
	IChangeArea * changeArea;
public:
	void setChangeArea(IChangeArea * changeArea);
	void onInit(fstream& fs, int worldHeight) override;
	void onIntersect(MovableBox* other) override;
	void update(float dt)override;
	Gate3();
	~Gate3();
};

