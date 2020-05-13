#include "Dxlib.h"	// DxLibײ���؂��g�p����
#include "SceneMng.h"

#define SCREEN_SIZE_X (1280)
#define SCREEN_SIZE_Y (720)

void SceneMng::Run(void)
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		
		ClsDrawScreen();

		ScreenFlip();
	}

}

const VECTOR2 SceneMng::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X, SCREEN_SIZE_Y);
}

SceneMng::SceneMng()
{
}


SceneMng::~SceneMng()
{
}

bool SceneMng::sysInit(void)
{
	// ���я���
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);				// true:window�@false:�ٽ�ذ�
	SetWindowText("StickHumanFighters");
	if (DxLib_Init() == -1) return false;	// DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);		// �ЂƂ܂��ޯ��ޯ̧�ɕ`��


	return true;
}