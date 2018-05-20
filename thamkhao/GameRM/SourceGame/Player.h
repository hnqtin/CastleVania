#pragma once
#include "MovableObject.h"
#include"KEY.h"
enum PLAYER_ACTION
{
	PLAYER_ACTION_STAND,//0
	PLAYER_ACTION_WAIT,//1
	PLAYER_ACTION_RUN,//2
	PLAYER_ACTION_JUMP//3
};

enum PLAYER_STATE
{
	PLAYER_STATE_STAND,
	PLAYER_STATE_JUMP,
	PLAYER_STATE_GO
};

class Player :
	public MovableObject
{
private:
	KEY * key;
	PLAYER_STATE playerState;
public:
	CREATE_INSTANCE_INSIDE(Player);
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);

	void setPlayerState(PLAYER_STATE playerState);

	Player();
	~Player();
	void update();
};

