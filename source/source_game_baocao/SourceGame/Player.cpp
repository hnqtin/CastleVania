#include "Player.h"
CREATE_INSTANCE_OUTSIDE(Player);
#include"ConsoleLogger.h"
#include"MorningStar.h"
#include"ScoreBar.h"
#include"BoomerangSw.h"
#include"GameSound.h"

void Player::goToStair(int xDestination, int yDestination)
{
	goToAction.setGoto(this, xDestination, yDestination, getGlobalValue("player_goto_stair_time"), getDt());
}

void Player::setSubWeapon(SubWeaponItem * subWeapon)
{
	this->subWeapon = subWeapon;
}

bool Player::isGoUpStair()
{
	return (isUpRightStair && getDirection() == Right) || (!isUpRightStair && getDirection() == Left);
}

void Player::setIsOnStair(bool isOnStair)
{
	this->isOnStair = isOnStair;
	if (isOnStair)
	{
		setIsLastGoToStair(false);
		setHeight(getGlobalValue("player_height"));
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
	deadDelay.init(getGlobalValue("player_dead_delay"));
	simonStairActionBefore = -1;
	isDead = false;
	needRestoreMorningStar = false;
	setSubWeapon(0);

	isThrowSubWeapon = false;

	obtainMorningStarDelay.init(getGlobalValue("player_obtain_moning_star_delay"));
}


Player::~Player()
{
}

void Player::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (!getIsOnStair())
		MovableObject::onCollision(other, nx, ny, collisionTime);
}

bool Player::createSubweapon()
{
	if (isThrowSubWeapon)
	{
		return true;
	}
	if (ScoreBar::getInstance()->getHeartCount() == 0)
		return false  ;
	switch (subWeapon->subWeaponType)
	{
	case SUB_WEAPON_ITEM_TYPE_BOOMERANG:
	{
		if (!BoomerangSw::isExists)
		{
			isThrowSubWeapon = true;
			auto boomerang = new BoomerangSw();
			boomerang->xInit = getX();
			boomerang->setX(getX());
			boomerang->setY(getY()-5);
			boomerang->setDirection(getDirection());
			ScoreBar::getInstance()->increaseHeartCount(-1);
			return true;
		}
		return false;
	}
	case SUB_WEAPON_ITEM_TYPE_KNIFE:
		isThrowSubWeapon = true;
		return true;
	default:
		break;
	}

	return false;
}

bool Player::onGoTo()
{
	return goToAction.isOnGoTo();
}

void Player::update(float dt)
{
	//end update blink and injure
	obtainMorningStarDelay.update();
	if (obtainMorningStarDelay.isOnTime())
	{
		setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_OBTAIN_MORNING_STAR);
		setDx(0);
		setVx(0);
		setDy(0);
		setVy(0);
		return;

	}

	if (isDead)
	{
		deadDelay.update();
		setAction(SIMON_PLAYER_ACTION_SIMON_DIE);
		setVx(0);
		setHeight(getCurrentFrameHeight());
		MovableObject::update(dt);
		if (deadDelay.isTerminated())
		{
			int currentArea = changeArea->getCurrentAreaIndex();
			if (currentArea == 5)
				currentArea = 4;
			boss->restore();
			changeArea->changeArea(currentArea);
			changeArea->resetLocation();
			Camera::getInstance()->preventMoving = false;
			ScoreBar::getInstance()->restoreHealth();
			ScoreBar::getInstance()->restoreBossHealth();
			MorningStar::getInstance()->setType(MORNINGSTAR_TYPE_1);
			needRestoreMorningStar = true;
			isDead = false;
		}

		return;
	}


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

	if (isOnAttack && isThrowSubWeapon && getIsLastFrame())
	{
		isThrowSubWeapon = false;
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
		isLastGoToStair = false;
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
			if (isPauseAnimation() == false && getAction() < SIMON_PLAYER_ACTION_SIMON_STAIR_ATTACK_UP)
			{
				isOnAttack = false;
			}
			else
			{
				if (simonStairActionBefore == -1)
					simonStairActionBefore = getAction();
				//action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_GO_UP_STAIR;
				if (isGoUpStair())
				{
					setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAIR_ATTACK_UP);
				}
				else
				{
					setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAIR_ATTACK_DOWN);
				}
				setPauseAnimation(false);
				MorningStar::getInstance()->setAlive(true);
			}

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
				if (key->isUpDown && subWeapon != 0)
				{
					if (!createSubweapon())
					{
						MorningStar::getInstance()->setAlive(true);
					}
				}
				else
				{
					MorningStar::getInstance()->setAlive(true);
				}
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
			if (key->isUpDown && subWeapon != 0)
			{
				if (!createSubweapon())
				{
					MorningStar::getInstance()->setAlive(true);
				}

			}
			else
			{
				MorningStar::getInstance()->setAlive(true);
			}
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
