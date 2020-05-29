#pragma once
#include <memory>
#include "BaseScene.h"

class GameCtrl;

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	Unique_Base UpDate(Unique_Base own)override;

private:
	void Init(void)override;
	void Draw(void);

	std::unique_ptr<GameCtrl> gameCtrl;
};

