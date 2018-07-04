#pragma once
#include"Config.h"
#include"Sprite.h"
#include"BaseObject.h"
#include"World.h"
#include"Camera.h"
class Game
{
	static Game* instance;
	Stage** stages;

	int currentStageIndex;

public:
	static Game* getInstance();
	Stage* currentStage();

	void nextStage();

	void init();
	void update(float dt);
	void render();

	Game(void);
	~Game(void);
};

