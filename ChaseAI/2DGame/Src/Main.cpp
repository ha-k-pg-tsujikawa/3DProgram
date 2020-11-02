#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>
#include "Engine/Engine.h"
#include "Common/Vec.h"
#include "../Enemy.h"
#include "../Player.h"
#include<vector>


// ゲーム処理
void GameProcessing();
// 描画処理
void DrawProcessing();

Player player;
Enemy enemy;

std::vector<Base*> list;

/*
	エントリポイント
*/
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmpLine,
	_In_ INT       nCmdShow)
{

	// エンジンの初期化
	// ゲームループ開始前に1度だけ実行する
	if (Engine::Initialize(640, 480, "Sample") == false)
	{
		return 0;
	}

	Engine::LoadTexture("Player", "Res/Character01.png");
	Engine::LoadTexture("Enemy", "Res/Character02.png");

	list.push_back(&player);
	list.push_back(&enemy);

	//player.SetPos(100, 100);
	//enemy.SetPos(200, 200);

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// ゲーム処理
			GameProcessing();

			// 描画開始
			DrawProcessing();


		}
	}

	// エンジン終了
	// ゲームループ終了後に1度だけ実行する
	// テクスチャとサウンドファイルも全て解放する
	Engine::Release();

	// メモリリーク検出
	_CrtDumpMemoryLeaks();

	return 0;

} // プログラム終了

void GameProcessing()
{
	// 入力データの更新
	Engine::Update();

	enemy.SetPosPlayer(player.GetPos());

	for (auto obj : list)
	{
		obj->Update();
	}

	//player.Update();
	//enemy.Update();
}

void DrawProcessing()
{
	// 描画開始
	Engine::StartDrawing(0);

	// foreach(配列の中身を自動ですべて通す)
	for (auto obj : list)
	{
		obj->Draw();
	}

	// イテレーターを利用したもの
	//for (std::vector<Base*>::iterator itr = list.begin(); itr != list.end(); ++itr)
	//{
	//	(*itr)->Draw();
	//}
	//player.Draw();
	//enemy.Draw();

	// 描画終了
	Engine::FinishDrawing();
}
