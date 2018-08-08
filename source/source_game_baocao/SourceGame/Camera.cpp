#include "Camera.h"
#include"MovableObject.h"
#include"Player.h"

CREATE_INSTANCE_OUTSIDE(Camera);

void Camera::setPlayer(MovableObject * player)
{
	this->player = player;
}


void Camera::setCameraLimit(ICameraLimit * cameraLimit)
{
	this->cameraLimit = cameraLimit;
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
	if (player == 0)
	{
		return;
	}
	if ((player->getNextFrameX() > this->getMidX() && player->getDx() > 0) ||
		(player->getNextFrameX() < this->getMidX() && player->getDx() < 0))
	{
		this->setDx(player->getDx());
	}
	else
	{
		this->setDx(0);
	}

	if (this->getNextFrameX() < cameraLimit->getLeft() && getDx() < 0)
	{
		setX(cameraLimit->getLeft());
		setDx(0);
	}
	if (this->getNextFrameX() + getWidth() > cameraLimit->getRight() && getDx() > 0)
	{
		setX(cameraLimit->getRight() - getWidth());
		setDx(0);
	}

	if (player->getNextFrameX() < cameraLimit->getLeft() && player->getDx() < 0)
	{
		player->setX(cameraLimit->getLeft());
		player->setDx(0);
	}
	if (player->getNextFrameX() + player->getWidth() > cameraLimit->getRight() && player->getDx() > 0)
	{
		player->setX(cameraLimit->getRight() - player->getWidth());
		player->setDx(0);
	}
	// Khi simon rot xuong duoi camera
	if (player->getBottom() < this->getBottom() && player->getDy() < 0 && Player::getInstance()->isDead==false)
	{
		Player::getInstance()->isDead = true;
		Player::getInstance()->deadDelay.start();
	}

}

Camera::Camera()
{
	setPlayer(0);
}


Camera::~Camera()
{
}
