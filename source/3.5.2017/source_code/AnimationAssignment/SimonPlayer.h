#pragma once
#include "MovableObject.h"
#include"Weapon.h"

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

enum SIMON_PLAYER_STATE
{
	SIMON_PLAYER_STATE_NORMAL,
	SIMON_PLAYER_STATE_ATTACK,
	SIMON_PLAYER_STATE_ON_BRIDGE
};


class SimonPlayer :
	public MovableObject
{
	static SimonPlayer* instance;
	SIMON_PLAYER_STATE simonPlayerState;
	BaseObject* contactObject;
public:
	static SimonPlayer* getInstance();

	void update();
	void render();
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
	void onLastFrameAnimation();
	void setHeight(float height);

	SIMON_PLAYER_ACTION currentAttackAction;

	void setContactObject(BaseObject* obj);
	void setState(SIMON_PLAYER_STATE state);


	SimonPlayer();
	~SimonPlayer();
};

