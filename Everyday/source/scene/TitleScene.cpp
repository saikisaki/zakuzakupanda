#include "DxLib.h"
#include "TitleScene.h"
#include "../input/GameCtrl.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::~TitleScene()
{
	Init();
}

void TitleScene::Init(void)
{
	gameCtrl = std::make_unique<GameCtrl>();
}

Unique_Base TitleScene::UpDate(Unique_Base own)
{
	gameCtrl->UpDate();

	if (gameCtrl->GetPadDataTrg(BUTTON_TYPE::ENTER))
	{
		return std::make_unique<GameScene>();
	}

	Draw();

	return std::move(own);
}

void TitleScene::Draw(void)
{
	DrawString(200, 200, "エンターキーを押してください", 0xffffff);
}