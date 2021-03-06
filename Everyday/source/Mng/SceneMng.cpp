#include "Dxlib.h"	// DxLibﾗｲﾌﾞﾗﾘを使用する
#include "SceneMng.h"
#include "../scene/TitleScene.h"

#define SCREEN_SIZE_X (1280)
#define SCREEN_SIZE_Y (720)

SceneMng::SceneMng()
{
	SystemInit();
}


SceneMng::~SceneMng()
{
}

bool SceneMng::SystemInit(void)
{
	// ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("StickHumanFighters");
	if (DxLib_Init() == -1) return false;	// DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);		// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	_frame = 0;
	return true;
}

void SceneMng::Run(void)
{
	activeScene = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();
		activeScene = activeScene->UpDate(std::move(activeScene));
		_frame++;
		ScreenFlip();
	}
}

const VECTOR2 SceneMng::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X, SCREEN_SIZE_Y);
}

void SceneMng::ResetFrame(void)
{
	_frame = 0;
}
