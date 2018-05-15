#include "QuadTree.h"
#include"Collision.h"

QuadTreeNode * QuadTree::getRootNode()
{
	return rootnode;
}

void QuadTree::setRootNode(QuadTreeNode * rootnode)
{
	this->rootnode = rootnode;
}

void QuadTree::init(const char * quadtreePath, BaseObject** allObjects, int worldHeight)
{
	ReadFileManager fileManager(quadtreePath);
	int nodesCount = fileManager.linesCount();
	int id, x, y, width, height, objectsCount, nodes, objectIndex, parentId;
	QuadTreeNode* currentNode;
	BaseObject** objectsOfNode;
	QuadNodeType quadNodeType;
	map<int, QuadTreeNode*> quadTreeNodeTable;

	for (size_t i = 0; i < nodesCount; i++)
	{
		id = fileManager.nextInt();
		if (id == 0)
		{
			rootnode = new QuadTreeNode();
			currentNode = rootnode;
		}
		else
		{
			currentNode = new QuadTreeNode();
			parentId = id / 10;
			quadNodeType = (QuadNodeType)(id % 10);
			auto parent = quadTreeNodeTable[parentId];
			switch (quadNodeType)
			{
			case QNT_TOP_LEFT:
				parent->setTopLeftNode(currentNode);
				break;
			case QNT_TOP_RIGHT:
				parent->setTopRightNode(currentNode);
				break;
			case QNT_BOTTOM_LEFT:
				parent->setBottomLeftNode(currentNode);
				break;
			case QNT_BOTTOM_RIGHT:
				parent->setBottomRightNode(currentNode);
				break;
			default:
				break;
			}
		}
		currentNode->setId(id);
		quadTreeNodeTable[id] = currentNode;
		x = fileManager.nextInt();
		y = worldHeight - fileManager.nextInt();
		width = fileManager.nextInt();
		height = fileManager.nextInt();
		nodes = fileManager.nextInt();
		objectsCount = fileManager.nextInt();
		currentNode->setObjectsCount(objectsCount);
		currentNode->set(x, y, width, height);

		if (objectsCount > 0)
		{
			objectsOfNode = new BaseObject*[objectsCount];
			currentNode->setObjects(objectsOfNode);
			for (size_t iObject = 0; iObject < objectsCount; iObject++)
			{
				objectIndex = fileManager.nextInt();
				objectsOfNode[iObject] = allObjects[objectIndex];
			}
		}
	}
}

void QuadTree::update(CollisionsObjectCollection* collection)
{
	auto alls = collection->getCollection(CT_ALL);
	for (int i = 0;i < alls->Count;i++)
	{
		auto obj = alls->at(i);
		if (!Collision::AABBCheck(obj, camera) && !Collision::AABBCheck(obj->getInitBox(), camera))
		{
			obj->restoreLocation();
			collection->removeObject(obj);
		}
	}
	rootnode->fillObject(collection, camera);
}

QuadTree::QuadTree()
{
	camera = Camera::getInstance();
}


QuadTree::~QuadTree()
{
}
