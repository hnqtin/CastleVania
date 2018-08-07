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
	virtual void onDecreaseHealth();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void onIntersect(MovableBox* other) override;
	void restoreLocation() override;
	virtual void onContactPlayer();
	virtual void onContactWeapon();
	virtual bool canAttackPlayer();
	Enemy();
	~Enemy();
};

