#pragma once
#include <vector>
#include "BaseScene.h"
#include "../unit/Obj.h"

class Referee;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own);		// 毎ﾌﾚｰﾑ処理するものをまとめた関数
private:
	bool CheckHit(const VECTOR2& posA, float radiusA, const VECTOR2& posB, float radiusB);
	bool IsHit();
	bool EnemyKillingMistake();
	std::unique_ptr<Referee> _ui;
	std::vector<Shared_Obj> _objList;		// キャラクターを管理するList
	std::vector<Shared_Obj> _itemList;
	void Init(void)override;

	int _frameCnt;
};

