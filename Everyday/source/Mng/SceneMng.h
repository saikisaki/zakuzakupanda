#pragma once
#include "../scene/BaseScene.h"
#include"../common/VECTOR2.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:
	static SceneMng &GetInstance(void)			// ‚±‚Ì¸×½‚ÌÎß²İÀ‚ğæ“¾‚·‚éA‚±‚±‚Å¼İ¸ŞÙÄİ‚Ìó‘Ô‚É‚µ‚Ä‚¢‚é
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
	Unique_Base activeScene;	// Še¼°İ‚É±¸¾½‚·‚é‚½‚ß‚ÌÕÆ°¸Îß²İÀ°
	
};

