#include "ItemBoomerang.h"
#include"ScoreBar.h"
#include"Player.h"
REGISTER_OBJECT_GAME(ItemBoomerang, SI_IBOOMERANG)

void ItemBoomerang::onPlayerContact()
{
	ScoreBar::getInstance()->setSubWeapon(this);
	Player::getInstance()->setSubWeapon(this);
}


ItemBoomerang::ItemBoomerang()
{
	setSprite(SpriteManager::getInstance()->getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_ITEM_BOOMERANG);
	subWeaponType = SUB_WEAPON_ITEM_TYPE::SUB_WEAPON_ITEM_TYPE_BOOMERANG;

}


ItemBoomerang::~ItemBoomerang()
{
}
