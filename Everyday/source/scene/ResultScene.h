#pragma once
#include "BaseScene.h"

class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	ResultScene(int defeatNum);
	~ResultScene();

	Unique_Base UpDate(Unique_Base own)override;
private:
	void Init(void)override;
	void Draw();

	int _defeatNum;		// ‘Œ‚”jƒ|ƒCƒ“ƒg
};

