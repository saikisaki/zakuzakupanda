#pragma once
#include "BaseScene.h"

class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	ResultScene(const int defeatNum);
	~ResultScene();

	Unique_Base UpDate(Unique_Base own)override;
private:
	void Init(void)override;
	int _defeatNum;
	void Draw();
};

