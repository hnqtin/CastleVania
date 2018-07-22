#include "Gate3.h"
#include"Player.h"
#include"Camera.h"

REGISTER_OBJECT_GAME(Gate3, SI_GATE_3)

void Gate3::setChangeArea(IChangeArea * changeArea)
{
	this->changeArea = changeArea;
}

void Gate3::onInit(fstream & fs, int worldHeight)
{
	string name;
	fs >> name >> playerX >> name >> playerY >> name >> nextArea;
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
