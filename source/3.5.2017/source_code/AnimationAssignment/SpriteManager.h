#pragma once
#include"Sprite.h"
//2 nhiem vu
//1 index cua sprite
//2 id cua doi tuong
enum SPRITE_INFO
{
	SI_GROUND=-1,
	SI_ZOMBIE,
	SI_PANTHER,
	SI_SIMON,
	SI_BAT,
	SI_CANDLE,
	SI_BONE_DRAGON,
	SI_FRANKENSTEIN,
	SI_EXPLOSION_EFFECT,
	SI_SMALL_HEART,
	SI_EAGLE,
	SI_MERMAN,
	SI_BRIDGE,
	SI_COUNT
};
class SpriteManager
{
	Sprite** sprites;
	int nSprite;
	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();
	static Sprite* getSprite(SPRITE_INFO spriteIndex);
	Sprite** getSprites();
	SpriteManager();
	~SpriteManager();
};

