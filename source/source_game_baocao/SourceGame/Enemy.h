#pragma once
#include "MovableObject.h"
#include"Player.h"
class Enemy :
	public MovableObject
{
	int health;
public:
	void setHealth(int health);
	int getHealth();
	void onInit(fstream& fs, int worldHeight) override{}
	void setDirectionFollowPlayer();
	virtual void onDeath();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void onIntersect(MovableBox* other) override;
	void restoreLocation() override;
	Enemy();
	~Enemy();
};

