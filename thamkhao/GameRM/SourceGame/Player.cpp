#include "Player.h"


CREATE_INSTANCE_OUTSIDE(Player);

void Player::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
	MovableObject::onCollision(other, nx, ny, collisionTime);
}

void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

Player::Player()
{
	setSprite(SpriteManager::getSprite(SI_ROCKMAN));
	setDirection(DIR_RIGHT);
	key = KEY::getInstance();
	setPlayerState(PLAYER_STATE::PLAYER_STATE_STAND);
}


Player::~Player()
{
}

void Player::update()
{
	double time = getTimeGame();
	PLAYER_ACTION playerAction;


	//set direction and ax by key

	bool keyMoveDown = key->isLeftDown || key->isRightDown;

	if (key->isLeftDown)
	{
		if (getDirection() == DIR_RIGHT)
		{
			setVx(0);
		}
		setDirection(DIR_LEFT);
	}
	else if (key->isRightDown)
	{
		if (getDirection() == DIR_LEFT)
		{
			setVx(0);
		}
		setDirection(DIR_RIGHT);
	}

	// set jump state
	if (key->isJumpPress && isOnGround())
	{
		setVy(getGlobalValue("player_vy_jump"));
	}

	// set normal state
	if (!isOnGround())
	{
		setPlayerState(PLAYER_STATE_JUMP);
	}
	else
	{
		if (keyMoveDown)
		{
			setPlayerState(PLAYER_STATE_GO);
		}
		else
		{
			if (getVx() == 0)
			{
				setPlayerState(PLAYER_STATE_STAND);
			}
		}

	}

	switch (playerState)
	{
	case PLAYER_STATE_STAND:
		playerAction = PLAYER_ACTION::PLAYER_ACTION_STAND;
		setAx(0);
		setVx(0);
		break;
	case PLAYER_STATE_JUMP:
		playerAction = PLAYER_ACTION::PLAYER_ACTION_JUMP;
		if (keyMoveDown)
		{
			setVx(getDirection()* getGlobalValue("player_max_vx"));
		}
		else
		{
			setVx(0);
		}
		if (isOnGround())
		{
			setPlayerState(PLAYER_STATE::PLAYER_STATE_STAND);
		}
		break;
	case PLAYER_STATE_GO:
	{
		double maxVx = getGlobalValue("player_max_vx");
		playerAction = PLAYER_ACTION::PLAYER_ACTION_RUN;
		float nextVx = 0;
		if (keyMoveDown)
		{
			setAx(getDirection()* getGlobalValue("player_ax_normal"));
			nextVx = getVx() + getAx()*time;
			if (nextVx* getDirection() > maxVx)
			{
				setVx(getDirection()*maxVx);
				setAx(0);
			}
		}
		else
		{
			setAx(-getDirection()* getGlobalValue("player_ax_normal"));
			nextVx = getVx() + getAx()*time;
			if (nextVx*getDirection() <= 0)
			{
				setVx(0);
				setAx(0);
			}
		}

		break;
	}
	default:
		break;
	}


	setAction(playerAction);
	MovableObject::update();
}

