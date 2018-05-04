#include "Camera.h"
#include"SimonPlayer.h"


Camera * Camera::instance = 0;
Camera * Camera::getInstance()
{
	if (instance == 0)
		instance = new Camera();
	return instance;
}

D3DXMATRIX Camera::getWorldToViewMatrix()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -this->getX();
	matrix._42 = this->getY();
	return matrix;
}

void Camera::getWorldToViewLocation(int xw, int yw, int & xv, int & yv)
{
	D3DXMATRIX w2vMatrix = getWorldToViewMatrix();
	D3DXVECTOR3 pos3(xw, yw, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &w2vMatrix);

	xv = MatrixResult.x;
	yv = MatrixResult.y;
}

void Camera::update()
{
	updateLocation();
	if ((simon->getNextFrameX() > this->getMidX() && simon->getDx() > 0) ||
		(simon->getNextFrameX() < this->getMidX() && simon->getDx() < 0))
	{
		this->setDx(simon->getDx());
	}
	else
	{
		this->setDx(0);
	}

	if (this->getNextFrameX() < 0 && getDx() < 0)
	{
		setX(0);
		setDx(0);
	}
	if (this->getNextFrameX() + getWidth() > 1024 && getDx() > 0)
	{
		setX(1024 - getWidth());
		setDx(0);
	}

}

Camera::Camera()
{
	simon = SimonPlayer::getInstance();
}


Camera::~Camera()
{
}
