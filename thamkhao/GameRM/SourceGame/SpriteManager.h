#pragma once
#include"Sprite.h"
enum SPRITE_INFO
{
	SI_GROUND = -1,
	SI_ROCKMAN = 0,
	SI_SIMON,//1
	SI_LINHNHAY,//2
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

