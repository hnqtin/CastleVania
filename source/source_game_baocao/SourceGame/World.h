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
class Stage :
	public TileMap,
	public ICameraLimit,
	public IChangeArea
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


public:
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

	void setPlayer(MovableObject* player);

	CollisionsObjectCollection* getCollisionsObjectCollection();
	Stage();
	~Stage();
	void update(float dt);
	void render();

	int getLeft();
	int getRight();
};

