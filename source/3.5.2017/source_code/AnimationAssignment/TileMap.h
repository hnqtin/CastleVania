#pragma once
#include"Texture.h"
#include"Camera.h"
class TileMap
{
	// hinh tilesheet . trong thu muc co file ten tilesheet
	Texture* tilesheet;
	// ma tran bieu dien tile
	int** matrix;
	// so dong tile cua map
	int rowCount;
	// so cot tile cua map
	int columnCount;
	// so cot tile cua tilesheet
	int tilesheetColumnCount;
	// chieu rong cua tile
	int tileWidth;
	// chieu cao cua tile
	int tileHeight;
	// chieu cao cua world
	int worldHeight;
public:
	int getWorldHeight();
	TileMap();
	void init(const char* tilesheetPath, const char* matrixPath);
	void renderTile(int rowIndex, int columnIndex, Camera* camera);
	void renderTiles(int rowBegin, int rowEnd, int columnBegin, int columnEnd, Camera* camera);
	virtual void render(Camera* camera);
	~TileMap();
};

