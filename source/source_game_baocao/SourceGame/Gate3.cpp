#include "Gate3.h"
#include"Player.h"
#include"Camera.h"

REGISTER_OBJECT_GAME(Gate3, SI_GATE_3)

void Gate3::setValue(const char * propertyName, int value)
{
	if (strcmp(propertyName, "playerX") == 0)
	{
		playerX = value;
	}
	else if(strcmp(propertyName, "playerY") == 0)
	{
		playerY = value;
	}
	else if (strcmp(propertyName, "nextArea") == 0)
	{
		nextArea = value;
	}
}

void Gate3::setChangeArea(IChangeArea * changeArea)
{
	this->changeArea = changeArea;
}

void Gate3::onInit(fstream & fs, int worldHeight)
{
	string name1,name2,name3;
	int val1, val2, val3;
	fs >> name1 >> val1 >> name2 >> val2 >> name3 >> val3;

	setValue(name1.c_str(), val1);
	setValue(name2.c_str(), val2);
	setValue(name3.c_str(), val3);

	playerY = worldHeight- playerY;
	BaseObject::onInit(fs, worldHeight);
}

void Gate3::onIntersect(MovableBox * other)
{
	auto player = Player::getInstance();
	auto camera = Camera::getInstance();
	if (player->getIsOnStair())
	{
		player->setX(playerX);
		player->setY(playerY);
		player->goToAction.setOnGoTo(false);
		player->setDx(0);
		player->setDy(0);
		changeArea->changeArea(nextArea);
		camera->setY(changeArea->getCurrentArea()->getY());
	}
}

void Gate3::update(float dt)
{
}

Gate3::Gate3()
{
	setPhysicsEnable(false);
}


Gate3::~Gate3()
{
}
