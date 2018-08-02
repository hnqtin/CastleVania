#include "World.h"
#include"Collision.h"
#include"ConsoleLogger.h"
#include"AdditionalObject.h"
#include"MorningStar.h"
#include"Gate1.h"
#include"Gate3.h"
#include"Player.h"
#include"VampireBat.h"
#include"Gate4.h"
void Stage::changeArea(int areaIndex)
{
	currentAreaIndex = areaIndex;
	Camera::getInstance()->setCameraLimit(&areas[currentAreaIndex]);
}

int Stage::getCurrentAreaIndex()
{
	return currentAreaIndex;
}

void Stage::init(const char* tilesheetPath,
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
	initArea(cameraLocationPath);
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

		// objectFuncts : Danh sach cac con tro ham (REGISTER_OBJECT_GAME la cai tao ra con tro ham do)

		for (size_t iObjectFunct = 0; iObjectFunct < objectFuncts->size(); iObjectFunct++)
		{
			// voi moi spriteid se tao ra vung nho tuong ung
			gameObject = (BaseObject*)objectFuncts->at(iObjectFunct)(spriteId);
			if (gameObject != 0)
				break;
		}
		// neu khong co con tro ham nao tao ra vung nho doi tuong
		if (gameObject == 0)
		{
			gameObject = new BaseObject();
		}

		if (spriteId == SI_GATE_1)
		{
			((Gate1*)gameObject)->setChangeArea(this);
		}

		if (spriteId == SI_GATE2)
		{
			((Gate2*)gameObject)->setChangeArea(this);
		}

		if (spriteId == SI_GATE_3)
		{
			((Gate3*)gameObject)->setChangeArea(this);
		}

		if (spriteId == SI_GATE_4)
		{
			((Gate4*)gameObject)->intf = gate4Inf;
		}

		if (spriteId == SI_VAMPIRE_BAT)
		{
			((VampireBat*)gameObject)->setChangeArea(this);
			Player::getInstance()->boss = dynamic_cast<IBoss*>(gameObject);
		}

		Player::getInstance()->changeArea = this;

		gameObject->set(x, getWorldHeight() - y, width, height);
		Rect* initBox = new Rect();
		// set init box de restore
		initBox->set(x, getWorldHeight() - y, width, height);
		gameObject->setInitBox(initBox);
		// set sprite de hien hinh
		gameObject->setSpriteId(spriteId);
		gameObject->setCollisionType(collisionType);
		gameObject->onInit(fs, getWorldHeight());
		// dua gameobject vao mang
		gameObjects[i] = gameObject;
		//collisionObjectCollection.getCollection((COLLISION_TYPE)collisionType)->_Add(gameObject);
	}
}

void Stage::initQuadtree(const char * quadtreePath)
{
	quadTree.build(quadtreePath, gameObjects, getWorldHeight());
}

void Stage::initCollisionTypeCollides(const char * collisionTypeCollidesPath)
{
	fstream fs(collisionTypeCollidesPath);
	fs >> nCollisionTypeCollides;
	int c1;
	int c2;
	collisionTypeCollides = new CollisionTypeCollide*[nCollisionTypeCollides];
	for (int i = 0; i < nCollisionTypeCollides; i++)
	{
		fs >> c1 >> c2;
		collisionTypeCollides[i] = new CollisionTypeCollide((COLLISION_TYPE)c1, (COLLISION_TYPE)c2);
	}
}

void Stage::initArea(const char * areaPath)
{
	ifstream fs(areaPath);
	ignoreLineIfstream(fs, 1);
	fs >> areasCount;

	areas = new Area[areasCount];
	int x, y, width, height, cx, cy, sx, sy;
	for (size_t i = 0; i < areasCount; i++)
	{
		ignoreLineIfstream(fs, 6);
		fs >> x >> y >> width >> height;
		areas[i].set(x, getWorldHeight() - y, width, height);
		ignoreLineIfstream(fs, 2);
		fs >> cx >> cy;
		ignoreLineIfstream(fs, 2);
		fs >> sx >> sy;
		areas[i].initCameraSimonLocation(cx, getWorldHeight() - cy, sx, getWorldHeight() - sy);
	}
}

void Stage::resetCameraAndPlayerLocation()
{
	camera->setLocation(areas[currentAreaIndex].getCameraX(),
		areas[currentAreaIndex].getCameraY());
	player->setLocation(areas[currentAreaIndex].getSimonX(),
		areas[currentAreaIndex].getSimonY());
}

void Stage::setPlayer(MovableObject * player)
{
	this->player = player;
}

void Stage::setGate2(BaseObject * gate2)
{
	this->gate2 = (Gate2*)gate2;
}

Area * Stage::getCurrentArea()
{
	return &areas[currentAreaIndex];
}

CollisionsObjectCollection * Stage::getCollisionsObjectCollection()
{
	return CollisionsObjectCollection::getInstance();
}

Stage::Stage()
{
	camera = Camera::getInstance();
	gate2 = 0;
	changeAreaState = CHANGE_AREA2_STATE::CHANGE_AREA2_STATE_CAMERA_MOVE_TEMP;
}


Stage::~Stage()
{
}

void Stage::update(float dt)
{

	if (gate2 != 0)
	{
		switch (changeAreaState)
		{
		case CHANGE_AREA2_STATE_CAMERA_MOVE_TEMP:
			player->setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND);
			player->setHeight(getGlobalValue("player_height"));
			player->setDy(0);
			player->setVy(0);
			player->setY(gate2->getBottom() + player->getHeight());
			camera->moveX(getGlobalValue("change_state_camera_move"));
			if (areas[currentAreaIndex].getRight() - camera->getleft() < camera->getWidth() / 2)
			{
				changeAreaState = CHANGE_AREA2_STATE_GATE2_OPENING;
				gate2->setState(GATE2_STATE::GATE2_STATE_OPENING);
			}
			break;
		case CHANGE_AREA2_STATE_GATE2_OPENING:
			gate2->performUpdate(dt);
			camera->moveX(0);
			if (gate2->getActionFrameIndex() == 1)
			{
				gate2->setState(GATE2_STATE::GATE2_STATE_OPENED);
				changeAreaState = CHANGE_AREA2_STATE_SIMON_MOVE;
				gate2->performUpdate(dt);
			}
			break;
		case CHANGE_AREA2_STATE_SIMON_MOVE:
			player->setVx(0);
			player->moveX(getGlobalValue("change_state_simon_move"));
			player->setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_WALK);
			player->updateAnimation();
			if (player->getleft() - gate2->getRight() > 16)
			{
				gate2->setState(GATE2_STATE::GATE2_STATE_CLOSING);
				changeAreaState = CHANGE_AREA2_STATE_GATE2_CLOSING;
				player->setAction(SIMON_PLAYER_ACTION::SIMON_PLAYER_ACTION_SIMON_STAND);
				gate2->setActionFrameIndex(0);
			}
			break;
		case CHANGE_AREA2_STATE_GATE2_CLOSING:
			gate2->performUpdate(dt);
			if (gate2->getActionFrameIndex() == 1)
			{
				gate2->setState(GATE2_STATE::GATE2_STATE_INVISIBLE);
				gate2->performUpdate(dt);
				changeAreaState = CHANGE_AREA2_STATE_CAMERA_MOVE_OFFICAL;

				for (size_t i = 0; i < areasCount; i++)
				{
					if (areas[i].getleft() > areas[currentAreaIndex].getLeft())
					{
						changeArea(i);
						break;
					}
				}
			}
			break;
		case CHANGE_AREA2_STATE_CAMERA_MOVE_OFFICAL:
		{
			camera->moveX(getGlobalValue("change_state_camera_move"));
			if (camera->getX() >= areas[currentAreaIndex].getX())
			{
				gate2->setWidth(0);
				gate2 = 0;
				changeAreaState = CHANGE_AREA2_STATE::CHANGE_AREA2_STATE_CAMERA_MOVE_TEMP;
			}
			break;
		}
		default:
			break;
		}
		return;
	}

	quadTree.update(getCollisionsObjectCollection());
	camera->update();
	MorningStar::getInstance()->performUpdate(dt);
	if (player != 0)
		player->performUpdate(dt);
	AdditionalObject::objectsUpdate();

	auto allObjectInFrame = getCollisionsObjectCollection()->getCollection(CT_ALL);

	for (size_t i = 0; i < allObjectInFrame->Count; i++)
	{
		auto obj = allObjectInFrame->at(i);
		obj->performUpdate(dt);
		if (player != 0)
			Collision::CheckCollision(player, obj);
	}
	auto collisionObjectCollection = *getCollisionsObjectCollection();
	for (int i = 0; i < nCollisionTypeCollides; i++)
	{
		auto collection1 = collisionObjectCollection.getCollection(collisionTypeCollides[i]->getCollisionType1());
		auto collection2 = collisionObjectCollection.getCollection(collisionTypeCollides[i]->getCollisionType2());
		for (int iC1 = 0; iC1 < collection1->size(); iC1++)
		{
			for (int iC2 = 0; iC2 < collection2->size(); iC2++)
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

	MorningStar::getInstance()->render();
}

int Stage::getLeft() { return 0; }

int Stage::getRight() { return getWorldWidth(); }
