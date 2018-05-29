#pragma once
#include "MovableObject.h"
#include"KEY.h"

#include"GameTime.h"
#include"DelayTime.h"

enum SIMON_PLAYER_ACTION
{
	SIMON_PLAYER_ACTION_SIMON_GO_INTO_NEXTSTATE,
	SIMON_PLAYER_ACTION_SIMON_INJURED,
	SIMON_PLAYER_ACTION_SIMON_DIE,
	SIMON_PLAYER_ACTION_SIMON_STAND,
	SIMON_PLAYER_ACTION_SIMON_WALK,
	SIMON_PLAYER_ACTION_SIMON_JUMP,
	SIMON_PLAYER_ACTION_SIMON_ATTACK,
	SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT,
	SIMON_PLAYER_ACTION_SIMON_ATTACK3,
	SIMON_PLAYER_ACTION_SIMON_GO_UP_STAIR,
	SIMON_PLAYER_ACTION_SIMON_GO_DOWN_STAIR
};


class Player :
	public MovableObject
{
	KEY* key;

	DelayTime d;

	bool isOnAttack;

public:
	void setIsOnAttack(bool isOnAttack);
	CREATE_INSTANCE_INSIDE(Player);
	Player();
	~Player();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

	void update();
};

