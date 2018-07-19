#include "Stair.h"
REGISTER_OBJECT_GAME(Stair, SI_STAIR)
#include"Player.h"
#include"KEY.h"
#include"Collision.h"
#include"ConsoleLogger.h"

void Stair::onInit(fstream & fs, int worldHeight)
{
	string name;
	int direction;
	fs >> name >> direction;
	setDirection(direction);
}

void Stair::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{

}

void Stair::onIntersect(MovableBox * other)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
}

void Stair::update(float dt)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();

}

void Stair::playerMoveUp()
{
}

void Stair::playerMoveDown()
{
}

Stair::Stair()
{

}


Stair::~Stair()
{
}
