#include "Player.h"
CREATE_INSTANCE_OUTSIDE(Player);


Player::Player()
{
	setSprite(SpriteManager::getInstance()->getSprite(SI_SIMON));
	setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND);
	key = KEY::getInstance();
	d.init(3000);
}


Player::~Player()
{
}

void Player::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{

	MovableObject::onCollision(other, nx, ny, collisionTime);

}

void Player::update()
{
	d.update();
	SIMON_PLAYER_ACTION action;
	if (isOnGround()) // is on ground
	{
		if (key->isPDown)
		{
			d.start();
		}

		if (d.isTerminated())
		{
			setVy(getGlobalValue("player_vy_jump"));
		}

		setHeight(getGlobalValue("player_height"));
		if (key->isLeftDown)
		{
			setDirection(Direction::Left);
		}
		if (key->isRightDown)
		{
			setDirection(Direction::Right);
		}
		if (key->isDownDown) //is sit
		{
			//sit down
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_JUMP;
			setHeight(getGlobalValue("player_jump_height"));
		}
		else // is not sit
		{
			bool isMoveDown = key->isLeftDown || key->isRightDown;

			if (isMoveDown) // is move
			{
				// move
				setVx(getDirection()* getGlobalValue("player_vx"));
				action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_WALK;
			}
			else // is not move
			{
				// stand
				setVx(0);
				action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND;
			}
			if (key->isJumpPress && isOnGround()) //is key jump press
			{
				setVy(getGlobalValue("player_vy_jump"));
			}
		}
	}
	else // is not ongroud
	{
		// jump
		setHeight(getGlobalValue("player_jump_height"));
		action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_JUMP;
		if (getVy() < getGlobalValue("player_vy_fall_stand")) // is fall
		{
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND;
			setHeight(getGlobalValue("player_height"));
		}
	}



	setAction(action);
	MovableObject::update();

}
