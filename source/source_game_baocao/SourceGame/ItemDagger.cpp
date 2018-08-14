#include "ItemDagger.h"
#include"ScoreBar.h"
#include"Player.h"
REGISTER_OBJECT_GAME(ItemDagger, SI_IDAGGER);


void ItemDagger::onPlayerContact()
{
	ScoreBar::getInstance()->setSubWeapon(this);
	Player::getInstance()->setSubWeapon(this);
}

ItemDagger::ItemDagger()
{
	setAction(MISC_SPRITE_ID_ITEM_DAGGER);
	subWeaponType = SUB_WEAPON_ITEM_TYPE::SUB_WEAPON_ITEM_TYPE_DAGGER;

}


ItemDagger::~ItemDagger()
{
}
