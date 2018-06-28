#include "World.h"
#include"Collision.h"
#include"ConsoleLogger.h"
#include"AdditionalObject.h"

void World::init(const char* tilesheetPath,
	const char* matrixPath,
	const char* objectsPath,
	const char* quadtreePath,
	const char* collisionTypeCollidesPath,
	const char * cameraLocationPath)
{
	TileMap::init(tilesheetPath, matrixPath);
	initCollisionTypeCollides(collisionTypeCollidesPath);
	initObjects(objectsPath);
	initQuadtree(quadtreePath);
	initCameraLocation(cameraLocationPath);

}

void World::initObjects(const char * objectsPath)
{
	auto objectFuncts = getCreateObjectFuncts();
	int collisionType, spriteId, x, y, width, height;
	BaseObject* gameObject = 0;
	fstream fs(objectsPath);
	fs >> nObjects;
	gameObjects = new BaseObject*[nObjects];
	for (size_t i = 0; i < nObjects; i++)
	{
		fs >> spriteId >> collisionType >> x >> y >> width >> height;
		for (size_t iObjectFunct = 0; iObjectFunct < objectFuncts->size(); iObjectFunct++)
		{
			gameObject = (BaseObject*)objectFuncts->at(iObjectFunct)(spriteId);
			if (gameObject != 0)
				break;
		}
		if (gameObject == 0)
		{
			gameObject = new BaseObject();
		}

		gameObject->set(x, getWorldHeight() - y, width, height);
		Rect* initBox = new Rect();
		initBox->set(x, getWorldHeight() - y, width, height);
		gameObject->setInitBox(initBox);
		gameObject->setSpriteId(spriteId);
		gameObject->setCollisionType(collisionType);
		gameObject->onInit(fs, getWorldHeight());
		gameObjects[i] = gameObject;
		//collisionObjectCollection.getCollection((COLLISION_TYPE)collisionType)->_Add(gameObject);
	}
}

void World::initQuadtree(const char * quadtreePath)
{
	quadTree.build(quadtreePath, gameObjects, getWorldHeight());
}

void World::initCollisionTypeCollides(const char * collisionTypeCollidesPath)
{
	fstream fs(collisionTypeCollidesPath);
	fs >> nCollisionTypeCollides;
	int c1;
	int c2;
	collisionTypeCollides = new CollisionTypeCollide*[nCollisionTypeCollides];
	for (int i = 0;i < nCollisionTypeCollides;i++)
	{
		fs >> c1 >> c2;
		collisionTypeCollides[i] = new CollisionTypeCollide((COLLISION_TYPE)c1, (COLLISION_TYPE)c2);
	}
}

void World::initCameraLocation(const char * cameraLocationPath)
{
	ifstream fs(cameraLocationPath);
	ignoreLineIfstream(fs, 1);
	fs >> cameraStartX >> cameraStartY;
	ignoreLineIfstream(fs, 2);
	fs >> simonStartX >> simonStartY;
}

void World::resetCameraAndPlayerLocation()
{
	camera->setLocation(cameraStartX, cameraStartY);
	player->setLocation(simonStartX, simonStartY);
}

void World::setPlayer(MovableObject * player)
{
	this->player = player;
}

CollisionsObjectCollection * World::getCollisionsObjectCollection()
{
	return CollisionsObjectCollection::getInstance();
}

World::World()
{
	camera = Camera::getInstance();
}


World::~World()
{
}

void World::update()
{
	quadTree.update(getCollisionsObjectCollection());
	camera->update();
	if (player != 0)
		player->performUpdate();
	AdditionalObject::objectsUpdate();

	auto allObjectInFrame = getCollisionsObjectCollection()->getCollection(CT_ALL);

	for (size_t i = 0; i < allObjectInFrame->Count; i++)
	{
		auto obj = allObjectInFrame->at(i);
		obj->performUpdate();
		if (player != 0)
			Collision::CheckCollision(player, obj);
	}
	auto collisionObjectCollection = *getCollisionsObjectCollection();
	for (int i = 0;i < nCollisionTypeCollides;i++)
	{
		auto collection1 = collisionObjectCollection.getCollection(collisionTypeCollides[i]->getCollisionType1());
		auto collection2 = collisionObjectCollection.getCollection(collisionTypeCollides[i]->getCollisionType2());
		for (int iC1 = 0;iC1 < collection1->size();iC1++)
		{
			for (int iC2 = 0;iC2 < collection2->size();iC2++)
			{
				Collision::CheckCollision(collection1->at(iC1), collection2->at(iC2));
			}
		}
	}
}

void World::render()
{
	TileMap::render(camera);
	auto allObjectInFrame = getCollisionsObjectCollection()->getCollection(CT_ALL);

	for (size_t i = 0; i < allObjectInFrame->Count; i++)
	{
		allObjectInFrame->at(i)->render();
	}
	if (player != 0)
		player->render();
}

int World::getLeft() { return 0; }

int World::getRight() { return getWorldWidth(); }
