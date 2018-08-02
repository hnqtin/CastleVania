#pragma once
#include "TileMap.h"
#include"BaseObject.h"
#include"SpriteManager.h"
#include"Camera.h"
#include"CollisionsObjectCollection.h"
#include"CollisionTypeCollide.h"
#include"ICameraLimit.h"
#include"QuadTree.h"
#include"Config.h"
#include"Area.h"
#include"IChangeArea.h"
#include"IChangeArea2.h"
#include"Gate2.h"
#include"IGate4Interface.h"


enum CHANGE_AREA2_STATE
{
	CHANGE_AREA2_STATE_CAMERA_MOVE_TEMP,
	CHANGE_AREA2_STATE_GATE2_OPENING,
	CHANGE_AREA2_STATE_SIMON_MOVE,
	CHANGE_AREA2_STATE_GATE2_CLOSING,
	CHANGE_AREA2_STATE_CAMERA_MOVE_OFFICAL,
};


class Stage :
	public TileMap,
	public ICameraLimit,
	public IChangeArea,// IPlayerWorld
	public IChangeArea2 // IDoorWorld
{
	BaseObject** gameObjects;
	int nObjects;
	Camera* camera;

	CollisionTypeCollide** collisionTypeCollides;
	int nCollisionTypeCollides;
	MovableObject* player;
	QuadTree quadTree;

	Area* areas;
	int currentAreaIndex;
	int areasCount;

	CHANGE_AREA2_STATE changeAreaState;

	Gate2* gate2;

public:
	IGate4Interface * gate4Inf;
	void init(const char* tilesheetPath,
		const char* matrixPath,
		const char* objectsPath,
		const char* quadtreePath,
		const char* collisionTypeCollidesPath,
		const char* areaPath);
	void initObjects(const char* objectsPath);
	void initQuadtree(const char* quadtreePath);
	void initCollisionTypeCollides(const char* collisionTypeCollidesPath);
	void initArea(const char* areaPath);
	void resetCameraAndPlayerLocation() override;
	void changeArea(int areaIndex) override;
	int getCurrentAreaIndex() override;

	void setPlayer(MovableObject* player);

	void setGate2(BaseObject* gate2) override;
	Area* getCurrentArea() override;

	CollisionsObjectCollection* getCollisionsObjectCollection();
	Stage();
	~Stage();
	void update(float dt);
	void render();

	int getLeft();
	int getRight();
};

