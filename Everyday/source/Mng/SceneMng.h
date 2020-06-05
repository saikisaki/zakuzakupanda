#pragma once
#include "../scene/BaseScene.h"
#include"../common/VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng &GetInstance(void)			// ���̸׽���߲�����擾����A�����żݸ���݂̏�Ԃɂ��Ă���
	{
		static SceneMng s_Instance;
		return s_Instance;
	}
	void Run(void);

	const VECTOR2 GetScreenSize(void);
	const int GetFrame(void) { return _frame; };
	void ResetFrame(void);

private:
	SceneMng();
	~SceneMng();

	bool SystemInit(void);
	int _frame;
	Unique_Base activeScene;	// �e��݂ɱ������邽�߂��ư��߲���
	
};

