#pragma once
#include"MovableBox.h"
#include<d3dx9.h>

class SimonPlayer;

class Camera : public MovableBox
{
	static Camera* instance;
	SimonPlayer* simon;
public:
	static Camera* getInstance();
	D3DXMATRIX getWorldToViewMatrix();
	void getWorldToViewLocation(int xW, int yW, int& xV, int& yV);
	void update();
	Camera();
	~Camera();
};

