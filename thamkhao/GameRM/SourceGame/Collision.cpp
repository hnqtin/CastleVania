#include "Collision.h"
#include<iostream>
#include<string>

using namespace std;


MovableBox * Collision::GetSweptBroadPhaseBox(MovableBox * box)
{
	MovableBox* bigBox = new MovableBox();
	bigBox->setX(box->getDx() > 0 ? box->getX() : (box->getX() + box->getDx()));
	bigBox->setY(box->getDy() > 0 ? (box->getY() + box->getDy()) : box->getY());
	bigBox->setWidth(box->getDx() > 0 ? (box->getWidth() + box->getDx()) : (box->getWidth() - box->getDx()));
	bigBox->setHeight(box->getDy() > 0 ? (box->getHeight() + box->getDy()) : (box->getHeight() - box->getDy()));
	return bigBox;
}

bool Collision::AABBCheck(Rect * M, Rect * S)
{
	return ((M->getX() < S->getX() + S->getWidth() && M->getX() + M->getWidth() > S->getX()) &&
		(M->getY() - M->getHeight() < S->getY() && M->getY() > S->getY() - S->getHeight()));
}

float Collision::SweptAABB(MovableBox* M, MovableBox* S, float & normalx, float & normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// Tính khoảng cách cần để xảy ra va chạm (InvEntry) và khoảng cách để ra khỏi va chạm (InvExit):
	if (M->getDx() > 0.0f)
	{
		xInvEntry = S->getX() - (M->getX() + M->getWidth());
		xInvExit = (S->getX() + S->getWidth()) - M->getX();
	}
	else
	{
		xInvEntry = (S->getX() + S->getWidth()) - M->getX();
		xInvExit = S->getX() - (M->getX() + M->getWidth());
	}

	if (M->getDy() > 0.0f)
	{
		yInvEntry = S->getY() - S->getHeight() - M->getY();
		yInvExit = S->getY() - (M->getY() - M->getHeight());
	}
	else
	{
		yInvEntry = S->getY() - (M->getY() - M->getHeight());
		yInvExit = (S->getY() - S->getHeight()) - M->getY();
	}

	// Tính thời gian để bắt đầu và chạm và thời gian để kết thúc va chạm theo mỗi phương:
	float xEntry, yEntry;
	float xExit, yExit;

	if (M->getDx() == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / (float)M->getDx();
		xExit = xInvExit / (float)M->getDx();
	}

	if (M->getDy() == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (float)M->getDy();
		yExit = yInvExit / (float)M->getDy();
	}

	// Thời gian để Box bắt đầu va chạm và thời gian để kết thúc va chạm:
	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	// Trường hợp không xảy ra va chạm:
	//Logger::getInstance()->write_text_to_log_file(std::to_string(GetVy()));
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	else // Trường hợp xảy ra va chạm:
	{
		// Xác định hướng của pháp tuyến khi va chạm:
		if (xEntry > yEntry)
		{
			if (M->getDx() < 0.0f) // Chạm vào bề mặt bên phải của block:
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else					// Chạm vào bề mặt bên trái của block:
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (M->getDy() < 0.0f) // Chạm vào bề mặt phía trên của block:
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else					// Chạm vào bề mặt phía dưới của block:
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// Trả về khoảng thời gian cần thiết để bắt đầu xảy ra va chạm:
		return entryTime;
	}
}

void Collision::CheckCollision(MovableBox * M, MovableBox * S)
{
	if (M->canCollision() == false || S->canCollision() == false)
		return;
	MovableBox* broadPhaseBox = GetSweptBroadPhaseBox(M);
	if (AABBCheck(broadPhaseBox, S))
	{
		delete broadPhaseBox; //*********************
		if (AABBCheck(M, S))
		{
			M->onIntersect(S);
			S->onIntersect(M);
			return;
		}
		float normalX = 0, normalY = 0;
		float nx, ny;
		float collisionTime = SweptAABB(M, S, nx, ny);
		if (collisionTime < 1)
		{
			if (M->getX() < S->getX() + S->getWidth() && M->getX() + M->getWidth() > S->getX())
			{
				if (M->getDy() > 0)
					normalY = -1;
				else
					normalY = 1;
			}
			else if (M->getY() - M->getHeight() < S->getY() && M->getY() > S->getY() - S->getHeight())
			{
				if (M->getDx() > 0)
					normalX = -1;
				else
					normalX = 1;
			}

			////chac chan co va cham
			//M->isCollision = true;
			//xu ly va cham
			M->onCollision(S, normalX, normalY,collisionTime);
			S->onCollision(M, normalX, normalY, collisionTime);
		}

		return;
	}
	delete broadPhaseBox;
}

Collision::Collision()
{
}

Collision::~Collision()
{
}