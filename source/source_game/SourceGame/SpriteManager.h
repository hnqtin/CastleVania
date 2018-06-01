#pragma once
#include"Sprite.h"
enum SPRITE_INFO
{
	SI_DOOR = -2,
	SI_GROUND = -1,
	SI_ZOMBIE, //0
	SI_PANTHER,//1
	SI_SIMON,//2
	SI_BAT,//3
	SI_CANDLE,//4
	SI_BONE_DRAGON,//5
	SI_FRANKENSTEIN,//6
	SI_EXPLOSION_EFFECT,//7
	SI_SMALL_HEART,//8
	SI_EAGLE,//9
	SI_MERMAN,//10
	SI_BRIDGE,//11
	SI_BONE_DRAGON_BODY,//12
	SI_MERMAN_BULLET,//13
	SI_IGOR,//14
	SI_WEAPON,//15
	SI_MISC,//16
	SI_LINH,//17
	SI_MEO,//18
    SI_GHOST,//19
	SI_COUNT
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

