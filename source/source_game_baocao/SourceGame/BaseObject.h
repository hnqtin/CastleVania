#pragma once
#include"PhysicsBox.h"
#include"DelayTime.h"
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
	virtual	void update(float dt);
public:
	Sprite * getSprite();
	void setSprite(Sprite* sprite);
	// hanh dong hien tai
	int getAction();
	// frame hien tai
	int getActionFrameIndex();
	// get width cua hinh tai action va frame hien tai
	int getCurrentFrameWidth();
	int getCurrentFrameHeight();
	
	void setAction(int actionIndex);
	void setActionFrameIndex(int actionFrameIndex);

	void updateAnimation();

	// active ve
	void setRenderActive(bool renderActive);
	bool getRenderActive();

	// animation interval
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
	virtual void setAlive(bool alive);

	bool canCollision();

	virtual bool canRemoveFromCamera();

	Direction getDirection();
	void setDirection(int direction);

	virtual void onInit(fstream& fs,int worldHeight);
	void setSpriteId(int spriteId);

	void performUpdate(float dt);
	virtual void render();
	virtual void onLastFrameAnimation();


	int distanceHorToFirstLocation();

	void onIntersect(MovableBox* other) override {}
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime) override {}


	BaseObject();
	~BaseObject();
};

