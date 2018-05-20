#pragma once
#include"Rect.h"
#include<fstream>
#include"BaseObject.h"
#include"CollisionsObjectCollection.h"
using namespace std;
class QuadTreeNode : public Rect
{
private:
	QuadTreeNode * TL, *TR, *BL, *BR;
	BaseObject** objects;
	int objectsCount;
	int id;
public:
	QuadTreeNode * topLeftNode();
	QuadTreeNode * topRightNode();
	QuadTreeNode * bottomLeftNode();
	QuadTreeNode * bottomRightNode();

	void setTopLeftNode(QuadTreeNode* tl);
	void setTopRightNode(QuadTreeNode* tr);
	void setBottomLeftNode(QuadTreeNode* bl);
	void setBottomRightNode(QuadTreeNode* br);

	int getObjectsCount();
	void setObjectsCount(int objectsCount);

	BaseObject** getObjects();
	void setObjects(BaseObject** objects);

	void fillObject(CollisionsObjectCollection* collection, Rect* viewport);

	int getId();
	void setId(int id);

	QuadTreeNode();
	~QuadTreeNode();
};

