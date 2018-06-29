#include "Player.h"
CREATE_INSTANCE_OUTSIDE(Player);
#include"ConsoleLogger.h"
#include"SimonRope.h"

void Player::setIsOnAttack(bool isOnAttack)
{
	this->isOnAttack = isOnAttack;
}

Player::Player()
{
	setSprite(SpriteManager::getInstance()->getSprite(SI_SIMON));
	setCollisionType(CT_PLAYER);
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

	if (getIsLastFrame() && isOnAttack)
	{
		setIsOnAttack(false);
		consoleLogger->LogLine(getActionFrameIndex());
	}

	if (key->isAttackPress)
	{
		setIsOnAttack(true);
	}



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
			setDx(0);
			setVx(0);

			if (isOnAttack)
			{
				action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT;
				SimonRope::getInstance()->setAlive(true);
			}
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

			if (isOnAttack)
			{
				action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_ATTACK;
				SimonRope::getInstance()->setAlive(true);
			}

			if (key->isJumpPress) //is key jump press
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

		if (isOnAttack)
		{
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_ATTACK;
			SimonRope::getInstance()->setAlive(true);
		}
	}



	setAction(action);
	MovableObject::update();

}
