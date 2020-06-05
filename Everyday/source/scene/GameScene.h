#pragma once
#include <vector>
#include "BaseScene.h"
#include "../unit/Obj.h"

class Referee;

using BombData = std::vector<std::pair<int, VECTOR2>>;
using BombVec = std::vector<BombData>;

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	
	Unique_Base UpDate(Unique_Base own)override;		// ���ڰя���������̂��܂Ƃ߂��֐�
private:
	bool CheckHit(const VECTOR2& posA, float radiusA, const VECTOR2& posB, float radiusB);
	void Init(void)override;
	bool IsHit();
	std::unique_ptr<Referee> _ui;
	std::vector<Shared_Obj> _objList;		// �L�����N�^�[���Ǘ�����List
	std::vector<Shared_Obj> _itemList;
	BombVec _bombCount;

	int _frameCnt;
};

