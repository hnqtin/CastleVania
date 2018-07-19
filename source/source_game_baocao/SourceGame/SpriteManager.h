#pragma once
#include"Sprite.h"
enum SPRITE_INFO
{
	SI_EXIT_STAIR = -8,
	SI_MERMAN_BULLET = -7,
	SI_CANDLE = -6,
	SI_TORCH = -5,
	SI_STAIR = -4,
	SI_GATE_1 = -3,
	SI_DOOR = -2,
	SI_GROUND = -1,
	SI_ZOMBIE, //0
	SI_PANTHER,//1
	SI_SIMON = 2,//2
	SI_GATE2,//3
	SI_MERMAN,//4
	SI_BAT,//5
	SI_EXPLOSION_EFFECT = 7,//7
	SI_WEAPON = 15,//15
	SI_MISC,//16
	SI_COUNT
};

enum MISC_SPRITE_ID
{
	MISC_SPRITE_ID_NUMBER,
	MISC_SPRITE_ID_MORNING_STAR,
	MISC_SPRITE_ID_LOST_HEALTH,
	MISC_SPRITE_ID_KNIFE_ITEM,
	MISC_SPRITE_ID_TORCH,
	MISC_SPRITE_ID_EXPLOSION_EFFECT,
	MISC_SPRITE_ID_CANDLE,
	MISC_SPRITE_ID_MERMAN_BULLET,
};

class SpriteManager
{
	Sprite** sprites;
	int nSprite;
	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();
	Sprite** getSprites();
	static Sprite* getSprite(SPRITE_INFO si);
	SpriteManager();
	~SpriteManager();
};

