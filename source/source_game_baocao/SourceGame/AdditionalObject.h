#pragma once
#include "MovableObject.h"
#include"SpriteManager.h"
#include"List.h"
class AdditionalObject :
	public MovableObject
{
private:
	bool needDelete;
	static List<AdditionalObject*>* objects;
public:
	static List<AdditionalObject*>* getObjects();
	static void objectsUpdate();
 	virtual void setNeedDelete(bool needDelete);
	void update(float dt);
	AdditionalObject();
	~AdditionalObject();
};

