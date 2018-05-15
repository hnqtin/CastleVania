#pragma once
#include"QuadTreeNode.h"
#include<map>
#include"ReadFileManager.h"
#include"Camera.h"

enum QuadNodeType
{
	QNT_TOP_LEFT= 1,
	QNT_TOP_RIGHT ,
	QNT_BOTTOM_LEFT ,
	QNT_BOTTOM_RIGHT
};

class QuadTree
{
private:
	QuadTreeNode * rootnode;
	Camera* camera;
public:
	QuadTree();

	// khoi tao quadtree tu file quadtree
	void init(const char* quadtreePath, BaseObject** allObjects, int mapHeight);

	//root node
	QuadTreeNode * getRootNode();
	void setRootNode(QuadTreeNode* rootnode);

	//bai sau
	void update(CollisionsObjectCollection* collection);
	~QuadTree();
};

