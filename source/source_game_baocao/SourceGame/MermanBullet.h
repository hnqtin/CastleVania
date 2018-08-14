#pragma once
#include "AdditionalObject.h"
#include"FollowPlayer.h"
#include"PlayerWeaponVictim.h"
class MermanBullet :
	public AdditionalObject, public IPlayerWeaponVictim
{
	int health;
public:
	FollowPlayer followPlayer;
	PlayerWeaponVictim weaponVictim;
	
	MermanBullet();
	~MermanBullet();


	void setHealth(int health) override;
	int getHealth() override;
	void setAlive(bool alive) override;

	void update(float dt) override;
	bool canAttackPlayer() { return true; }
	void onIntersect(MovableBox* other) override;
	void onCollision(MovableBox* other, int nx, int ny, float collisionTime);
};

