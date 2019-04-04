#include "GameMap.h"

void GameMap::LoadMap( const char *filepath)
{
	fstream fs(filepath);
	//fs >> mtotalTile;
	fs >> mtotalTile>> mrowCount >> mcolumnCount;
	matrixTile = new int *[mrowCount];
	for (int rowIndex = 0; rowIndex < mrowCount; rowIndex++)
	{
		matrixTile[rowIndex] = new int[mcolumnCount];
		for (int columIndex = 0; columIndex < mcolumnCount; columIndex++)
		{
			fs >> matrixTile[rowIndex][columIndex];
		}
	}
	fs.close();
	mTileMap = new Sprite("Resources/tileSet.png");
	
}

bool GameMap::isContain(RECT rect1, RECT rect2)
{
	if (rect1.left > rect2.right || rect1.right < rect2.left || rect1.top > rect2.bottom || rect1.bottom < rect2.top)
	{
		return false;
	}

	return true;
}

void GameMap::Draw()
{
	RECT rect;
	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::GetWidth() / 2 - mCamera->GetPosition().x,
		GameGlobal::GetHeight() / 2 - mCamera->GetPosition().y);
	for (int rowIndex = 0; rowIndex < mrowCount; rowIndex++)
	{
		
		for (int columIndex = 0; columIndex < mcolumnCount; columIndex++)
		{
			//mMap->SetSourceRect()
			rect.left =matrixTile[rowIndex][columIndex]* FrameWidth;
			rect.right = rect.left * FrameWidth;
			rect.top = 0;
			rect.bottom = rect.top + FrameHeight;
			D3DXVECTOR3 position(columIndex*FrameWidth + FrameWidth / 2, rowIndex*FrameHeight + FrameHeight / 2, 0);

		//	mMap->SetSourceRect(rect);
			if (mCamera != NULL)
			{
				RECT objRECT;
				objRECT.left = position.x - FrameWidth / 2;
				objRECT.top = position.y - FrameHeight / 2;
				objRECT.right = objRECT.left + FrameWidth;
				objRECT.bottom = objRECT.top + FrameHeight;

				//neu nam ngoai camera thi khong Draw
				if (isContain(objRECT, mCamera->GetBound()) == false)
					continue;
			}
			mTileMap->SetHeight(FrameHeight);
			mTileMap->SetWidth(FrameWidth);
			//position
			mTileMap->Draw(position,rect,D3DXVECTOR2(),trans);
		}
	}
}

void GameMap::SetCamera(Camera * camera)
{
	this->mCamera = camera;
}

GameMap::~GameMap()
{
	for (int i = 0; i < mrowCount; i++)
	{
		delete[]	matrixTile[i];
	}
	delete[]matrixTile;
	delete mTileMap;
	delete mCamera;
}

GameMap::GameMap(const char * filepath)
{
	LoadMap(filepath);
}

int GameMap::GetHeight()
{
	return mrowCount*FrameHeight;
}

int GameMap::GetWidth()
{
	return mcolumnCount * FrameWidth;
}
