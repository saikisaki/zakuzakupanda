#pragma once
#include "Obj.h"
#include "../input/GameCtrl.h"

class Player :
	public Obj
{
public:
	Player();
	Player(const VECTOR2& pos, const int& size);
	~Player();

	UNIT GetUnit(void) override;
	void SetMove(void) override;
	void Draw(void) override;

private:
	void Init(void);
	bool Explosion(void);

	int _playerH;		// プレイヤー用の画像

	int _bombSize;		// 爆風サイズ

	std::unique_ptr<GameCtrl> gameCtrl;		// キャラ操作用の画像
};

