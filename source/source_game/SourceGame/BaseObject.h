#pragma once
#include"PhysicsBox.h"
#include"GameTime.h"
#include"Sprite.h"
#include"Camera.h"
#include"SpriteManager.h"

class BaseObject : 
	public PhysicsBox
{
private:
	// hinh ve va animation
	Sprite* sprite;
	// chua action va frame cua animation
	int actionIndex, actionFrameIndex;
	// delay animation
	int interval;
	// id
	int spriteId;
	// delay animation
	GameTime* animationDelay;
	// huong mat cua doi
	Direction direction;
	// dung animation
	bool pauseAnimation;
	// xem doi tuong co hoat dong khong
	bool alive;
	// dung de restore location
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

	virtual bool canRemoveFromCamera();

	Direction getDirection();
	void setDirection(Direction direction);

	virtual void onInit(fstream& fs);
	void setSpriteId(int spriteId);

	void performUpdate();
	virtual void render();
	virtual void onLastFrameAnimation();

	int distanceHorToFirstLocation();


	BaseObject();
	~BaseObject();
};

