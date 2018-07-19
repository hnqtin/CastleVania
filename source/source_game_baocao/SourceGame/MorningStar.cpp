#include "MorningStar.h"
#include"Player.h"
#include"MorningStarAttack.h"

MorningStar * MorningStar::instance = 0;
MorningStar * MorningStar::getInstance()
{
	if (instance == 0)
	{
		instance = new MorningStar();
	}
	return instance;
}

void MorningStar::update(float dt)
{
	setAlive(false);
}

void MorningStar::render()
{
	if (!isAlive())
	{
		return;
	}
	setDirection(Player::getInstance()->getDirection());
	switch (morningStarType)
	{
	case MORNINGSTAR_TYPE_1:
		setAction(0);
		break;
	case MORNINGSTAR_TYPE_2:
		setAction(1);
		break;
	case MORNINGSTAR_TYPE_3:
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
			setX(Player::getInstance()->getleft() - getWidth());
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

	if (Player::getInstance()->isOnGround() == false)
	{
		moveY(6);
	}

	if (morningStarType == MORNINGSTAR_TYPE_1)
	{
		moveY(3);
	}

	BaseObject::render();
}

MorningStar::MorningStar()
{
	ifstream fs("Data/Sprites/SimonWeapon/weapon.location.txt");
	fs >> locations[0].x >> locations[0].y >> locations[1].x >> locations[1].y >> locations[2].x >> locations[2].y;
	setSprite(SpriteManager::getSprite(SI_WEAPON));
	morningStarType = MORNINGSTAR_TYPE_3;
	changeColorTime.setTimeDelay(getGlobalValue("weapon_change_color_time"));
	canCreateMorningStarAttack = true;
}


MorningStar::~MorningStar()
{
}
