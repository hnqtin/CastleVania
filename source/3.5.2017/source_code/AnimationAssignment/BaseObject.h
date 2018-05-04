#pragma once
#include"PhysicsBox.h"
#include"GameTime.h"
#include"Sprite.h"
#include"Camera.h"

class BaseObject : public PhysicsBox
{
	Sprite* sprite;
	int actionIndex, actionFrameIndex;
	int interval;
	int spriteId;
	GameTime* animationDelay;
	Direction direction;
	bool pauseAnimation;
	bool alive;
	Rect* initBox;
protected:
	virtual	void update();
public:
	Sprite * getSprite();
	void setSprite(Sprite* sprite);
	int getAction();
	int getActionFrameIndex();
	int getCurrentFrameWidth();
	int getCurrentFrameHeight();
	void setAction(int actionIndex);
	void setActionFrameIndex(int actionFrameIndex);
	void setInterval(int interval);
	int getInterval();
	Rect* getInitBox();
	void setInitBox(Rect* initBox);
	virtual void restoreLocation();

	void setPauseAnimation(bool pauseAnimation);
	bool isPauseAnimation();

	bool isAlive();
	void setAlive(bool alive);

	bool canCollision();

	Direction getDirection();
	void setDirection(Direction direction);

	virtual void onInit(fstream& fs);
	void setSpriteId(int spriteId);

	void performUpdate();
	virtual void render();
	virtual void onLastFrameAnimation();


	BaseObject();
	~BaseObject();
};

