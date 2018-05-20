#include "Stage.h"
#include"Collision.h"
#include"ConsoleLogger.h"
#include"AdditionalObject.h"
extern void ignoreLineIfstream(ifstream& fs, int lineCount);


void Stage::init(const char* tilesheetPath,
	const char* matrixPath,
	const char* objectsPath,
	const char* quadtreePath,
	const char* locationsPath,
	const char* collisionTypeCollidesPath)
{
	TileMap::init(tilesheetPath, matrixPath);
	initCollisionTypeCollides(collisionTypeCollidesPath);
	initObjects(objectsPath);
	initQuadtree(quadtreePath);
	initLocations(locationsPath);
}

void Stage::initObjects(const char * objectsPath)
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

		gameObject->set(x, getStageHeight() - y, width, height);
		Rect* initBox = new Rect();
		initBox->set(x, getStageHeight() - y, width, height);
		gameObject->setInitBox(initBox);
		gameObject->setSpriteId(spriteId);
		gameObject->setCollisionType(collisionType);
		gameObject->onInit(fs);
		gameObjects[i] = gameObject;
		//collisionObjectCollection.getCollection((COLLISION_TYPE)collisionType)->_Add(gameObject);
	}
}

void Stage::initQuadtree(const char * quadtreePath)
{
	quadTree.build(quadtreePath, gameObjects, getStageHeight());
}

void Stage::initCollisionTypeCollides(const char * collisionTypeCollidesPath)
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

void Stage::initLocations(const char* locationsPath)
{
	if (camera != 0 && player != 0)
	{
		ifstream fs(locationsPath);
		ignoreLineIfstream(fs, 1);
		int xCam, yCam, xPlayer, yPlayer;
		fs >> xCam >> yCam;
		ignoreLineIfstream(fs, 2);
		fs >> xPlayer >> yPlayer;
		camera->setLocation(xCam, yCam);
		player->setLocation(xPlayer, yPlayer);
	}

}

void Stage::setPlayer(MovableObject * player)
{
	this->player = player;
}

void Stage::setCamera(Camera * camera)
{
	this->camera = camera;
}

CollisionsObjectCollection * Stage::getCollisionsObjectCollection()
{
	return CollisionsObjectCollection::getInstance();
}

Stage::Stage()
{
}


Stage::~Stage()
{
}

void Stage::update()
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

void Stage::render()
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

int Stage::getLeft() { return 0; }

int Stage::getRight() { return getStageWidth(); }
