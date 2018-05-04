#include "SimonPlayer.h"
#include"SpriteManager.h"
#include"KEY.h"

SimonPlayer * SimonPlayer::instance = 0;
SimonPlayer * SimonPlayer::getInstance()
{
	if (instance == 0)
		instance = new SimonPlayer();
	return instance;
}

void SimonPlayer::update()
{
	SIMON_PLAYER_ACTION action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND;

	switch (simonPlayerState)
	{
	case SIMON_PLAYER_STATE_ON_BRIDGE:
	case SIMON_PLAYER_STATE_NORMAL:
	{
		//if (isOnGround())
		setVx(0);
		if ( KEY::getInstance()->isLeftDown)
		{
			setDirection(Left);
			setVx(-0.1);
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_WALK;
		}
		if ( KEY::getInstance()->isRightDown)
		{
			setDirection(Right);
			setVx(0.1);
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_WALK;
		}
		if (getVx() == 0)
		{
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND;
		}
		if (!isOnGround())
		{
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_JUMP;
		}
		if (isOnGround() && KEY::getInstance()->isJumpPress)
		{
			setVy(0.2);
		}

		if (KEY::getInstance()->isDownDown)
		{
			action = SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_JUMP;
			setHeight(23);
		}
		else
		{
			setHeight(30);
		}

		if (KEY::getInstance()->isAttackPress)
		{
			if (!KEY::getInstance()->isDownDown)
				currentAttackAction = SIMON_PLAYER_ACTION_SIMON_ATTACK;
			else
				currentAttackAction = SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT;
			simonPlayerState = SIMON_PLAYER_STATE_ATTACK;
		}
		break;
	}
	case SIMON_PLAYER_STATE_ATTACK:
	{
		if (isOnGround())
		{
			setVx(0);
		}
		if (getActionFrameIndex() == 2)
		{
			Weapon* weapon = new Weapon();
			if (getDirection() == Right)
			{
				weapon->setX(getX() + 22);
			}
			else
			{
				weapon->setX(getX() - weapon->getWidth());
			}
			weapon->setY(getY() - 12);
		}

		if (currentAttackAction == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
		{
			setHeight(23);
		}

		action = currentAttackAction;
		break;
	}
	default:
		break;
	}



	setAction(action);
	MovableObject::update();

	if (simonPlayerState == SIMON_PLAYER_STATE_ON_BRIDGE)
	{
		setY(contactObject->getTop() + getHeight());
		setDx(getDx() + contactObject->getDx());
		if (KEY::getInstance()->isJumpPress)
		{
			simonPlayerState = SIMON_PLAYER_STATE_NORMAL;
		}
	}
}

void SimonPlayer::render()
{
	MovableObject::render();
}

void SimonPlayer::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (other->getCollisionType() == CT_GROUND)
	{
		//van toc khong duoc tang dan deu khi dung tren san
		if (ny != 0)
			setVy(-0.1f); //****
		preventMoveWhenCollision(collisionTime, nx, ny);
	}
	MovableObject::onCollision(other, nx, ny, collisionTime);
}

void SimonPlayer::onLastFrameAnimation()
{
	if (simonPlayerState == SIMON_PLAYER_STATE_ATTACK)
	{
		simonPlayerState = SIMON_PLAYER_STATE::SIMON_PLAYER_STATE_NORMAL;
	}
}

void SimonPlayer::setHeight(float height)
{
	setY(getY() + (height - this->getHeight()));
	MovableObject::setHeight(height);
}

void SimonPlayer::setContactObject(BaseObject * obj)
{
	contactObject = obj;
}

void SimonPlayer::setState(SIMON_PLAYER_STATE state)
{
	simonPlayerState = state;
}

SimonPlayer::SimonPlayer()
{
	setSprite(SpriteManager::getInstance()->getSprites()[SI_SIMON]);
	setAction(3);
	setCollisionType(CT_PLAYER);

}


SimonPlayer::~SimonPlayer()
{
}
