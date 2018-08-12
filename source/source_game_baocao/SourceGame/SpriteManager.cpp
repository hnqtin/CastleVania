#include "SpriteManager.h"



SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
		instance = new SpriteManager();
	return instance;
}

Sprite ** SpriteManager::getSprites()
{
	return sprites;
}


Sprite * SpriteManager::getSprite(SPRITE_INFO si)
{
	return getInstance()->sprites[si];
}

SpriteManager::SpriteManager()
{
	Texture* enemiesImage = new Texture();
	enemiesImage->Init("Data/Sprites/Enemies/image.png", 0);
	enemiesImage->direction = Left;

	sprites = new Sprite*[SI_COUNT];


	sprites[SI_SIMON] = new Sprite();
	sprites[SI_SIMON]->ReadFromFile("Data/Sprites/Simon/info.simple.txt", "Data/Sprites/Simon/image.png");
	sprites[SI_SIMON]->img->direction = Right;

#pragma region Enemies

	sprites[SI_ZOMBIE] = new Sprite();
	sprites[SI_ZOMBIE]->readInfo("Data/Sprites/Enemies/zombie.info.txt");
	sprites[SI_ZOMBIE]->img = enemiesImage;

	sprites[SI_PANTHER] = new Sprite();
	sprites[SI_PANTHER]->readInfo("Data/Sprites/Enemies/panther.info.txt");
	sprites[SI_PANTHER]->img = enemiesImage;

	sprites[SI_MERMAN] = new Sprite();
	sprites[SI_MERMAN]->readInfo("Data/Sprites/Enemies/merman.info.txt");
	sprites[SI_MERMAN]->img = enemiesImage;

	sprites[SI_BAT] = new Sprite();
	sprites[SI_BAT]->readInfo("Data/Sprites/Enemies/bat.info.txt");
	sprites[SI_BAT]->img = enemiesImage;

	sprites[SI_VAMPIRE_BAT] = new Sprite();
	sprites[SI_VAMPIRE_BAT]->ReadFromFile("Data/Sprites/vampire_bat/info.simple.txt", "Data/Sprites/vampire_bat/bosses.png");
	sprites[SI_VAMPIRE_BAT]->img->direction = Right;

	sprites[SI_FLEAMAN] = new Sprite();
	sprites[SI_FLEAMAN]->readInfo("Data/Sprites/Enemies/fleaman.info.txt");
	sprites[SI_FLEAMAN]->img = enemiesImage;

	sprites[SI_SKELETON] = new Sprite();
	sprites[SI_SKELETON]->readInfo("Data/Sprites/Enemies/skeleton.info.txt");
	sprites[SI_SKELETON]->img = enemiesImage;

	sprites[SI_SKELETON_WEAPON] = new Sprite();
	sprites[SI_SKELETON_WEAPON]->readInfo("Data/Sprites/Enemies/skeleton_weapon.txt");
	sprites[SI_SKELETON_WEAPON]->img = enemiesImage;

	sprites[SI_RED_SKELETON] = new Sprite();
	sprites[SI_RED_SKELETON]->readInfo("Data/Sprites/Enemies/red_skeleton.info.txt");
	sprites[SI_RED_SKELETON]->img = enemiesImage;

	sprites[SI_MEDUSA_HEAD] = new Sprite();
	sprites[SI_MEDUSA_HEAD]->readInfo("Data/Sprites/Enemies/medusa_head.info.txt");
	sprites[SI_MEDUSA_HEAD]->img = enemiesImage;


	sprites[SI_DEATH] = new Sprite();
	sprites[SI_DEATH]->initFromSingleFrame("Data/Sprites/death/death.png");

#pragma endregion


	sprites[SI_EXPLOSION_EFFECT] = new Sprite();
	sprites[SI_EXPLOSION_EFFECT]->readInfo("Data/Sprites/Enemies/explosion.info.txt");
	sprites[SI_EXPLOSION_EFFECT]->img = enemiesImage;

	sprites[SI_WEAPON] = new Sprite();
	sprites[SI_WEAPON]->ReadFromFile("Data/Sprites/SimonWeapon/weapon.info.txt", "Data/Sprites/SimonWeapon/image.png");
	sprites[SI_WEAPON]->img->direction = Right;

	sprites[SI_GATE2] = new Sprite();
	sprites[SI_GATE2]->ReadFromFile("Data/Sprites/Gate2/info.simple.txt", "Data/Sprites/Gate2/image.png");
	sprites[SI_GATE2]->img->direction = Right;

	sprites[SI_MISC] = new Sprite();
	sprites[SI_MISC]->ReadFromFile("Data/Sprites/Misc/misc.info.txt", "Data/Sprites/Misc/misc.png");
	sprites[SI_MISC]->img->direction = Right;

	sprites[SI_DEATH_WEAPON] = new Sprite();
	sprites[SI_DEATH_WEAPON]->ReadFromFile("Data/Sprites/DeathWeapon/info.txt", "Data/Sprites/DeathWeapon/image.png");
	sprites[SI_DEATH_WEAPON]->img->direction = Right;

	sprites[SI_GATE_5] = sprites[SI_GATE2];
}


SpriteManager::~SpriteManager()
{
}
