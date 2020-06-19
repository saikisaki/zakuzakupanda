#include "DxLib.h"
#include "TitleScene.h"
#include "../input/GameCtrl.h"
#include "GameScene.h"
#include "../Mng/ImageMng.h"

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
	DrawGraph(300, 100, lpImageMng.GetID("image/title.png")[0], true);
	DrawString(500, 500, "エンターキーを押してください", 0xffffff);
}