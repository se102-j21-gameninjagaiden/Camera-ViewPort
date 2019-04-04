#include "Sprite.h"
#include "GameGlobal.h"

#include <fstream>
#include <iostream>
#include "Camera.h"
#define FrameWidth 32
#define FrameHeight 32
using namespace std;
class GameMap
{
public:
	GameMap(const char *filepath);
	int GetHeight();
	int GetWidth();
	void Draw();
	void SetCamera(Camera *camera);
	~GameMap();
private:
	void LoadMap(const char *filepath);
	int mrowCount, mcolumnCount, mtotalTile;
	bool isContain(RECT rect1, RECT rect2);

	int **matrixTile;
	Sprite * mTileMap;
	Camera *mCamera;
	
	


};