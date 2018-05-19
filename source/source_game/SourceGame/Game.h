#pragma once
#include"Config.h"
#include"Sprite.h"
#include"BaseObject.h"
#include"World.h"
#include"Camera.h"
class Game
{
	static Game* instance;
	World** stages;

	int currentStageIndex;

public:
	static Game* getInstance();
	World* currentStage();

	void nextStage();

	void init();
	void update();
	void render();

	Game(void);
	~Game(void);
};

