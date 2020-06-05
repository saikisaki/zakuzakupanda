#include <DxLib.h>
#include "ResultScene.h"
#include "../Mng/ImageMng.h"


ResultScene::ResultScene()
{
}

ResultScene::ResultScene(const int defeatNum)
{
	_defeatNum = defeatNum;
}

void ResultScene::Init(void)
{
}

ResultScene::~ResultScene()
{
}

Unique_Base ResultScene::UpDate(Unique_Base own)
{
	Draw();
	return std::move(own);
}

void ResultScene::Draw()
{
	DrawGraph(250, 200, lpImageMng.GetID("image/gameClear.png")[0], true);
	DrawFormatString(800, 450, 0xff0000, "撃破ポイント：%d", _defeatNum);
}
