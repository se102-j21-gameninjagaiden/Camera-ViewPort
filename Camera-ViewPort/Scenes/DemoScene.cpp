#include "DemoScene.h"

DemoScene::DemoScene()
{
    LoadContent();
}

void DemoScene::LoadContent()
{
    //set mau backcolor cho scene o day la mau xanh
	mMap = new GameMap("Resources/MaxtrixMap.txt");
	
	mCamera = new Camera(GameGlobal::GetWidth(), GameGlobal::GetHeight());
	mCamera->SetPosition(GameGlobal::GetWidth() / 2,
		 GameGlobal::GetHeight() / 2);

		
	mMap->SetCamera(mCamera);
	
}

void DemoScene::Update(float dt)
{
	if (IsKeyDown(DIK_LEFTARROW))
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(-CAMERA_SPEED, 0, 0));
			if (mCamera->GetPosition().x <= mCamera->GetWidth() / 2)
			{
				mCamera->SetPosition(mCamera->GetWidth() / 2, mCamera->GetPosition().y);

			}
	}
	if (IsKeyDown(DIK_RIGHTARROW))
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(CAMERA_SPEED, 0, 0));
		if (mCamera->GetPosition().x >= mMap->GetWidth() - GameGlobal::GetWidth() / 2)
		{
			mCamera->SetPosition(mMap->GetWidth() - GameGlobal::GetHeight() / 2, mCamera->GetPosition().y);

		}
	}
	if (IsKeyDown(DIK_UPARROW))
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, -CAMERA_SPEED, 0));
	}
	if (IsKeyDown(DIK_DOWNARROW))
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, CAMERA_SPEED, 0));
	}

   
}

void DemoScene::Draw()
{
	mMap->Draw();
}

void DemoScene::OnKeyDown(int keyCode)
{
	/*if (keyCode == VK_LEFT)
	{
		mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(-10, 0, 0));
		if (mCamera->GetPosition().x <=mCamera->GetWidth()/2)
		{
			mCamera->SetPosition(mCamera->GetWidth()/2, mCamera->GetPosition().y);

		}
	}*/

	//if (keyCode == VK_RIGHT)
	//{
	//	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(10, 0, 0));
	//	if (mCamera->GetPosition().x >= mMap->GetWidth()- GameGlobal::GetWidth()/2)
	//	{
	//		mCamera->SetPosition(mMap->GetWidth()-GameGlobal::GetHeight()/2, mCamera->GetPosition().y);
	//			
	//	}
	//
	//}

	//if (keyCode == VK_UP)
	//{
	//	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, -10, 0));
	///*	if (mCamera->GetPosition().y >= mMap->GetHeight())
	//	{
	//		mCamera->SetPosition(mCamera->GetPosition().x,mCamera->GetHeight()/2);

	//	}*/
	//}

	//if (keyCode == VK_DOWN)
	//{
	//	mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(0, 10, 0));
	//}
	
}

void DemoScene::OnKeyUp(int keyCode)
{

}

void DemoScene::OnMouseDown(float x, float y)
{
}

int DemoScene::IsKeyDown(int KeyCode)
{
	return (GameGlobal::GetCurrentKeyState()[KeyCode] & 0x80) > 0;
}