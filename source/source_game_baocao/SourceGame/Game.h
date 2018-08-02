#pragma once
#include"Config.h"
#include"Sprite.h"
#include"BaseObject.h"
#include"World.h"
#include"Camera.h"
#include"IGate4Interface.h"
class Game : public IGate4Interface
{
	static Game* instance;
	Stage** stages;

	int currentStageIndex;

public:
	static Game* getInstance();
	Stage* currentStage();

	void changeLevel(int levelIndex, int areaIndex) override;

	void nextStage();

	void init();
	void update(float dt);
	void render();

	Game(void);
	~Game(void);
};

