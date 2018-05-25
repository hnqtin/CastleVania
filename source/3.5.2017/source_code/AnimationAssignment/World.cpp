#include "World.h"
#include"SimonPlayer.h"
#include"Collision.h"
#include"BoneDragon.h"
#include"BossFrankensteinEnemy.h"
#include"Candle.h"
#include"Item.h"
#include"ExplosionEffect.h"
#include"BatEnemy.h"
#include"EagleEnemy.h"
#include"MermanEnemy.h"
#include"ConsoleLogger.h"
#include"Bridge.h"


void World::init(const char* tilesheetPath,
	const char* matrixPath,
	const char* objectsPath,
	const char* quadtreePath,
	const char* collisionTypeCollidesPath)
{
	TileMap::init(tilesheetPath, matrixPath);
	initCollisionTypeCollides(collisionTypeCollidesPath);
	initObjects(objectsPath);
	initQuadtree(quadtreePath);
}

void World::initObjects(const char * objectsPath)
{
	int collisionType, objectId, x, y, width, height;
	BaseObject* gameObject;
	fstream fs(objectsPath);
	fs >> nObjects;
	allObjectsInWorld = new BaseObject*[nObjects];
	for (size_t i = 0; i < nObjects; i++)
	{
		fs >> objectId >> collisionType >> x >> y >> width >> height;

		switch (objectId)
		{
		case SI_GROUND:
			gameObject = new BaseObject();
			break;
		case SI_BONE_DRAGON:
			gameObject = new BoneDragon();
			break;
		case SI_CANDLE:
			gameObject = new Candle();
			break;
		case SI_FRANKENSTEIN:
			gameObject = new BossFrankensteinEnemy();
			break;
		case SI_BAT:
			gameObject = new BatEnemy();
			break;
		case SI_EAGLE:
			gameObject = new EagleEnemy();
			break;
		case SI_MERMAN:
			gameObject = new MermanEnemy();
			break;
		case SI_BRIDGE:
			gameObject = new Bridge();
			break;
		default:
			gameObject = new BaseObject();
			break;
		}

		gameObject->set(x, getWorldHeight() - y, width, height);
		Rect* initBox = new Rect();
		initBox->set(x, getWorldHeight() - y, width, height);
		gameObject->setInitBox(initBox);
		gameObject->setSpriteId(objectId);
		gameObject->setCollisionType(collisionType);
		gameObject->onInit(fs);
		allObjectsInWorld[i] = gameObject;
		//collisionObjectCollection.getCollection((COLLISION_TYPE)collisionType)->_Add(gameObject);
	}
}

void World::initQuadtree(const char * quadtreePath)
{
	quadTree.init(quadtreePath, allObjectsInWorld, getWorldHeight());
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

CollisionsObjectCollection * World::getCollisionsObjectCollection()
{
	return &collisionObjectCollection;
}

World::World()
{
	camera = Camera::getInstance();
	simon = SimonPlayer::getInstance();
}


World::~World()
{
}

void World::update()
{


	quadTree.update(&collisionObjectCollection);
	camera->update();
	simon->performUpdate();

	auto allObjectInFrame = collisionObjectCollection.getCollection(CT_ALL);
	//xu ly update tat ca object tai thoi diem hien tai va va cham giua chung trong camera va simon
	for (size_t i = 0; i < allObjectInFrame->Count; i++)
	{
		auto obj = allObjectInFrame->at(i);
		obj->performUpdate();
		Collision::CheckCollision(simon, obj);
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

	auto enemiesCollection = collisionObjectCollection.getCollection(CT_ENEMY);
	auto weaponCollection = Weapon::getWeapons();
	for (size_t iweapon = 0; iweapon < weaponCollection->size(); iweapon++)
	{
		weaponCollection->at(iweapon)->performUpdate();
		if (!weaponCollection->at(iweapon)->isAlive())
		{
			weaponCollection->_Remove(weaponCollection->at(iweapon));
			iweapon--;
			continue;
		}
		for (size_t ienemy = 0; ienemy < enemiesCollection->size(); ienemy++)
		{
			Collision::CheckCollision(enemiesCollection->at(ienemy), weaponCollection->at(iweapon));
		}
	}

	auto explosionEffects = ExplosionEffect::getExplosionEffects();

	for (size_t iexp = 0; iexp < explosionEffects->size(); iexp++)
	{
		explosionEffects->at(iexp)->performUpdate();
		if (!explosionEffects->at(iexp)->isAlive())
		{
			explosionEffects->_Remove(explosionEffects->at(iexp));
			iexp--;
			continue;
		}
	}

	auto itemsCollection = Item::getItems();
	auto groundsCollection = collisionObjectCollection.getCollection(CT_GROUND);

	for (size_t iitem = 0; iitem < itemsCollection->size(); iitem++)
	{
		itemsCollection->at(iitem)->performUpdate();

		for (size_t iground = 0; iground < groundsCollection->size(); iground++)
		{
			Collision::CheckCollision(itemsCollection->at(iitem), groundsCollection->at(iground));
		}
		Collision::CheckCollision(simon, itemsCollection->at(iitem));

		if (!itemsCollection->at(iitem)->isAlive())
		{
			itemsCollection->_Remove(itemsCollection->at(iitem));
			iitem--;
			continue;
		}
	}
}

void World::render()
{
	TileMap::render(camera);
	auto allObjectInFrame = collisionObjectCollection.getCollection(CT_ALL);

	for (size_t i = 0; i < allObjectInFrame->Count; i++)
	{
		allObjectInFrame->at(i)->render();
	}

	auto explosionEffects = ExplosionEffect::getExplosionEffects();
	for (size_t iexp = 0; iexp < explosionEffects->size(); iexp++)
	{
		explosionEffects->at(iexp)->render();
	}

	auto itemsCollection = Item::getItems();
	for (size_t iitem = 0; iitem < itemsCollection->size(); iitem++)
	{
		itemsCollection->at(iitem)->render();
	}
	SimonPlayer::getInstance()->render();
}
