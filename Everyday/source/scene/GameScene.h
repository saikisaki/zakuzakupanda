#pragma once
#include "BaseScene.h"
class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own);		// ���ڰя���������̂��܂Ƃ߂��֐�
private:
	void Init(void)override;
};

