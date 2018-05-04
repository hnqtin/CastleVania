#pragma once
#include"Config.h"
#include"Sprite.h"
#include"BaseObject.h"
#include"World.h"
#include"Camera.h"
class Game
{
	static Game* instance;

	BaseObject* simonGoIntoNextStage;
	BaseObject* simonInjured;
	BaseObject* simonDie;
	BaseObject* simonWalk;
	BaseObject* simonJump;
	BaseObject* simonAttack1;
	BaseObject* simonAttack2;
	BaseObject* simonAttack3;
	BaseObject* simonGoUpStair;
	BaseObject* simonGoDownStair;

	BaseObject* enemy1;
	BaseObject* enemy2;
	BaseObject* enemy3;
	BaseObject* enemy4;
	BaseObject* enemy5;
	BaseObject* enemy6;
	BaseObject* enemy7;
	BaseObject* enemy8;
	BaseObject* enemy9;
	BaseObject* enemy10;

	World* world;

public:
	static Game* getInstance();
	void init();
	void update();
	void render();

	Game(void);
	~Game(void);
};

