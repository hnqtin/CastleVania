#pragma once

#include"SpriteManager.h"
#include"GameTime.h"

struct SCORE_LOCATION
{
	int X;
	int Y;
	int MaxLength;
};

class ScoreBar
{
	Sprite* miscSprite;
	Texture* scoreBar;
	void renderNumber(int num, int x, int y, int maxLength);
	void renderHealth();
	void renderSubWeapon();
	static ScoreBar* instance;
	SCORE_LOCATION lifeLocation;
	SCORE_LOCATION heartLocation;
	SCORE_LOCATION stageLocation;
	SCORE_LOCATION scoreLocation;
	SCORE_LOCATION timeLocation;
	SCORE_LOCATION healthLocation;
	SCORE_LOCATION subWeaponLocation;

	int health;
	int maxHealth;
	int playerLife;
	int heartCount;
	int currentStageNumber;
	int score;
	int time;
	GameTime timeGame;
public:
	static ScoreBar* getInstance();
	ScoreBar();
	~ScoreBar();
	void render();
	void update();

	int getPlayerLife();
	void setPlayerLife(int playerLife);
	void increasePlayerLife(int playerLife);

	int getHeartCount();
	void setHeartCount(int heartCount);
	void increaseHeartCount(int heartCount);

	int getScore();
	void setScore(int score);
	void increaseScore(int score);

	int getTime();
	void setTime(int time);
	void increaseTime(int time);

	int getHealth();
	void setHealth(int health);
	void increaseHealth(int health);

	void setCurrentStageNumber(int currentStageNumber);
};

