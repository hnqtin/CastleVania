#pragma once
#include "MovableBox.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a
#include<iostream>
using namespace std;

class Collision
{
public:
	static MovableBox* GetSweptBroadPhaseBox(MovableBox* box);
	static bool AABBCheck(Rect* M, Rect* S);
	static float SweptAABB(MovableBox* M, MovableBox* S, float &normalX, float &normalY);
	static float SweptAABB2(MovableBox* M, MovableBox* S, float &normalX, float &normalY);
	static void CheckCollision(MovableBox* M, MovableBox* S);

	/* CONSTRUCTOR & DESTRUCTOR */
	Collision();
	~Collision();
};
