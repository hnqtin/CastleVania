#include "Player.h"
CREATE_INSTANCE_OUTSIDE(Player);
#include"ConsoleLogger.h"
#include"MorningStar.h"

void Player::goToStair(int xDestination, int yDestination)
{
	goToAction.setGoto(this, xDestination, yDestination, getGlobalValue("player_goto_stair_time"), getDt());
}

void Player::setIsOnStair(bool isOnStair)
{
	this->isOnStair = isOnStair;
	if (isOnStair)
	{
		setIsLastGoToStair(false);
	}
}

bool Player::getIsOnStair()
{
	return isOnStair;
}

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

	blinkTime.setDeltaTime(getGlobalValue("player_blink_time"));
	blinkDelay.init(getGlobalValue("player_blink_delay"));
	simonStairActionBefore = -1;
}


Player::~Player()
{
}

void Player::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (!getIsOnStair())
		MovableObject::onCollision(other, nx, ny, collisionTime);
}

bool Player::onGoTo()
{
	return goToAction.isOnGoTo();
}

void Player::update(float dt)
{
	//end update blink and injure

	SIMON_PLAYER_ACTION action;

	if (getIsLastFrame() && isOnAttack)
	{
		setIsOnAttack(false);
		if (getIsOnStair()) {
			setAction(simonStairActionBefore);
			simonStairActionBefore = -1;
		}
	}

	if (key->isAttackPress)
	{
		setIsOnAttack(true);
	}


	if (goToAction.isOnGoTo())
	{
		setPauseAnimation(false);
		goToAction.update(dt);
		return;
	}

	if (isLastGoToStair)
	{
		setIsOnStair(false);
	}

	// update blink and injure
	blinkDelay.update();
	if (blinkDelay.isOnTime())
	{
		if (getAction() != SIMON_PLAYER_ACTION_SIMON_INJURED)
		{
			if (blinkTime.atTime())
			{
				setRenderActive(!getRenderActive());
			}
		}
	}

	if (blinkDelay.isTerminated())
	{
		setRenderActive(true);
	}

	if (getIsOnStair())
	{
		if (isOnAttack)
		{
			if (simonStairActionBefore == -1)
				simonStairActionBefore = getAction();
			//action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_GO_UP_STAIR;
			setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT);
			setPauseAnimation(false);
			MorningStar::getInstance()->setAlive(true);
		}
		else
		{
			if (key->isUpDown || key->isDownDown)
			{
				setPauseAnimation(false);
			}
			else
			{
				setPauseAnimation(true);
				setActionFrameIndex(1);
			}
			if (key->isUpDown)
			{
				this->moveUpStair(dt);
			}
			if (key->isDownDown)
			{
				this->moveDownStair(dt);
			}
		}
		return;
	}

	if (getAction() == SIMON_PLAYER_ACTION_SIMON_INJURED)
	{
		if (isOnGround())
		{
			setAction(SIMON_PLAYER_ACTION_SIMON_STAND);
		}
		MovableObject::update(dt);
		return;
	}






	if (isOnGround()) // is on ground
	{
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
				MorningStar::getInstance()->setAlive(true);
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
				MorningStar::getInstance()->setAlive(true);
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
			MorningStar::getInstance()->setAlive(true);
		}
	}

	// khi danh thi dung lai
	if (isOnAttack && isOnGround())
	{
		setVx(0);
	}


	setAction(action);
	MovableObject::update(dt);

}

void Player::moveUpStair(float dt)
{
	int yDestination = getY() + 8;
	int xDestination = getX() + 8;
	setDirection(Right);
	if (!isUpRightStair)
	{
		xDestination = getX() - 8;
		setDirection(Left);
	}
	moveByStair(xDestination, yDestination, dt);
	setAction(SIMON_PLAYER_ACTION_SIMON_GO_UP_STAIR);
}

void Player::moveDownStair(float dt)
{
	int yDestination = getY() - 8;
	int xDestination = getX() - 8;
	setDirection(Left);
	if (!isUpRightStair)
	{
		xDestination = getX() + 8;
		setDirection(Right);
	}
	moveByStair(xDestination, yDestination, dt);
	setAction(SIMON_PLAYER_ACTION_SIMON_GO_DOWN_STAIR);
}

void Player::moveByStair(int xDestination, int yDestination, float dt)
{
	goToAction.setGoto(this, xDestination, yDestination, getGlobalValue("player_goto_stair_time"), dt);
}

void Player::setisUpRightStair(bool isUpRightStair)
{
	this->isUpRightStair = isUpRightStair;
}

void Player::setIsLastGoToStair(bool isLastGoToStair)
{
	this->isLastGoToStair = isLastGoToStair;
}
