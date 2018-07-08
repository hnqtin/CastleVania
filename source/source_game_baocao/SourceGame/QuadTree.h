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
	QuadTreeNode * getRootNode();
	void setRootNode(QuadTreeNode* rootnode);
	void build(const char* quadtreePath, BaseObject** allObjects, int mapHeight);
	void update(CollisionsObjectCollection* collection);
	QuadTree();
	~QuadTree();
};

