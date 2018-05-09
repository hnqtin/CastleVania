#pragma once
#include "MovableBox.h"
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a
#include<iostream>
using namespace std;
class CollisionTest
{
public:

	// tim broadphase box
	static MovableBox* GetSweptBroadPhaseBox(MovableBox* box);
	// kiem tra giao nhau interserct
	static bool AABBCheck(Rect* M, Rect* S);
	//
	static float SweptAABB(MovableBox* M, MovableBox* S, float &normalX, float &normalY);
	// Kiem tra va xu ly va cham
	static void CheckCollision(MovableBox* M, MovableBox* S);

	CollisionTest();
	~CollisionTest();
};

