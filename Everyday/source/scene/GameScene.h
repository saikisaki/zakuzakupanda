#pragma once
#include "BaseScene.h"
class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own);		// –ˆÌÚ°Ñˆ—‚·‚é‚à‚Ì‚ğ‚Ü‚Æ‚ß‚½ŠÖ”
private:
	void Init(void)override;
};

