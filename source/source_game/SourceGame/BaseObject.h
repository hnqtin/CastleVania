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
	// xem doi tuong co ton tai khong
	// ton tai (co update co render va co xet va cham)
	bool alive;
	// dung de restore location
	Rect* initBox;
	bool renderActive;

	bool isLastFrame;

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
	void setRenderActive(bool renderActive);
	bool getRenderActive();
	void setInterval(int interval);
	int getInterval();
	Rect* getInitBox();
	void setInitBox(Rect* initBox);
	virtual void restoreLocation();

	void setPauseAnimation(bool pauseAnimation);
	bool isPauseAnimation();

	bool getIsLastFrame();
	void setIsLastFrame(bool isLastFrame);

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

