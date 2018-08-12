#include "SimonRope.h"
#include"Player.h"
#include"MorningStarAttack.h"

SimonRope * SimonRope::instance = 0;
SimonRope * SimonRope::getInstance()
{
	if (instance == 0)
	{
		instance = new SimonRope();
	}
	return instance;
}

void SimonRope::update(float dt)
{
	setAlive(false);
}

void SimonRope::render()
{
	if (!isAlive())
	{
		return;
	}
	setDirection(Player::getInstance()->getDirection());
	switch (simonRopeType)
	{
	case SIMON_ROPE_TYPE_1:
		setAction(0);
		break;
	case SIMON_ROPE_TYPE_2:
		setAction(1);
		break;
	case SIMON_ROPE_TYPE_3:
		if (getAction() < 2)
		{
			setAction(2);
		}
		if (changeColorTime.atTime())
		{
			int action = getAction();
			if (action == 2)
			{
				setAction(3);
			}
			else if (action == 3)
			{
				setAction(4);
			}
			else
			{
				setAction(2);
			}
		}
		break;
	default:
		break;
	}

	auto playerFrameIndex = Player::getInstance()->getActionFrameIndex();
	setActionFrameIndex(playerFrameIndex);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setDirection(Player::getInstance()->getDirection());



	if (getDirection() == Right)
	{
		switch (playerFrameIndex)
		{
		case 0:
			setX(Player::getInstance()->getX() - getCurrentFrameWidth() + locations[0].x);
			setY(Player::getInstance()->getY() - locations[0].y);
			break;
		case 1:
			setX(Player::getInstance()->getX() - getCurrentFrameWidth() + locations[1].x);
			setY(Player::getInstance()->getY() - locations[1].y);
			break;
		case 2:
			setX(Player::getInstance()->getX() + locations[2].x);
			setY(Player::getInstance()->getY() - locations[2].y);
			if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
			{
				setY(getY() + 2);
			}
			if (!Player::getInstance()->isOnGround())
			{
				setY(getY() - 2);
			}
			break;
		default:
			break;
		}
	}
	else
	{
		switch (playerFrameIndex)
		{
		case 0:
			setX(Player::getInstance()->getRight());
			setY(Player::getInstance()->getY() - locations[0].y);
			break;
		case 1:
			setX(Player::getInstance()->getRight());
			setY(Player::getInstance()->getY() - locations[1].y);
			break;
		case 2:
			setX(Player::getInstance()->getleft() -getWidth());
			setY(Player::getInstance()->getY() - locations[2].y);
			if (Player::getInstance()->getAction() == SIMON_PLAYER_ACTION_SIMON_ATTACK_SIT)
			{
				setY(getY() + 2);
			}
			if (!Player::getInstance()->isOnGround())
			{
				setY(getY() - 2);
			}
			break;
		default:
			break;
		}
	}

	if (playerFrameIndex == 1)
	{
		canCreateMorningStarAttack = true;
	}
	if (playerFrameIndex == 2)
	{
		if (canCreateMorningStarAttack)
		{
			MorningStarAttack* morningStarAttack = new MorningStarAttack();

			morningStarAttack->set(getX(), getY(), getWidth(), getHeight());
			canCreateMorningStarAttack = false;
		}
	}

	BaseObject::render();
}

SimonRope::SimonRope()
{
	ifstream fs("Data/Sprites/SimonWeapon/weapon.location.txt");
	fs >> locations[0].x >> locations[0].y >> locations[1].x >> locations[1].y >> locations[2].x >> locations[2].y;
	setSprite(SpriteManager::getSprite(SI_WEAPON));
	simonRopeType = SIMON_ROPE_TYPE_3;
	changeColorTime.setTimeDelay(getGlobalValue("weapon_change_color_time"));
	canCreateMorningStarAttack = true;
}


SimonRope::~SimonRope()
{
}
