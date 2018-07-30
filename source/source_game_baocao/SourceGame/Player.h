#pragma once
#include "MovableObject.h"
#include"KEY.h"

#include"GameTime.h"
#include"DelayTime.h"
#include"GoToAction.h"
#include"IChangeArea.h"

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
	SIMON_PLAYER_ACTION_SIMON_GO_DOWN_STAIR,
	SIMON_PLAYER_ACTION_SIMON_STAIR_ATTACK_UP,
	SIMON_PLAYER_ACTION_SIMON_STAIR_ATTACK_DOWN
};


class Player :
	public MovableObject
{
	KEY* key;
	bool isOnAttack;
	GameTime blinkTime;
	void goToStair(int xDestination, int yDestination);
	bool isOnStair;

	bool isUpRightStair;
	bool isLastGoToStair;


	int simonStairActionBefore;
public:

	DelayTime deadDelay;
	bool needRestoreMorningStar;
	IChangeArea * changeArea;

	bool isDead;
	bool isGoUpStair();
	GoToAction goToAction;
	void setIsOnStair(bool isOnStair);
	bool getIsOnStair();
	void setIsOnAttack(bool isOnAttack);
	CREATE_INSTANCE_INSIDE(Player);
	Player();
	~Player();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	bool onGoTo();
	void update(float dt);
	DelayTime blinkDelay;


	void moveUpStair(float dt);
	void moveDownStair(float dt);
	void moveByStair(int xDestination, int yDestination, float dt);
	void setisUpRightStair(bool isUpRightStair);
	void setIsLastGoToStair(bool isLastGoToStair);
};

