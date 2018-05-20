#pragma once
#include"Config.h"
#include"Sprite.h"
#include"BaseObject.h"
#include"Stage.h"
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
	void update();
	void render();

	Game(void);
	~Game(void);
};

