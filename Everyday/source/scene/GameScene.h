#pragma once
#include "BaseScene.h"
class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own);		// 毎ﾌﾚｰﾑ処理するものをまとめた関数
private:
	void Init(void)override;
};

