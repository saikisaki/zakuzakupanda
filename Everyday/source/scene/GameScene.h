#pragma once
#include <vector>
#include "BaseScene.h"
#include "../unit/Obj.h"
class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own);		// ���ڰя���������̂��܂Ƃ߂��֐�
private:
	std::vector<Shared_Obj> _objList;		// �L�����N�^�[���Ǘ�����List
	void Init(void)override;
};

