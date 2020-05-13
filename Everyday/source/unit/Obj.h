#pragma once
#include <memory>
#include "../common/Vector2.h"

enum class STATE	// キャラの現在の状態
{
	NORMAL,		// 通常
	EX,			// 特殊
	DEATH,		// 爆破
	INVINCIBLE, // 無敵
	MAX
};

enum class UNIT
{
	PLAYER,		// プレイヤーユニット
	ENEMY,		// 敵
	MAX
};

class Obj;
using Shared_Obj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	~Obj();
	virtual void Draw(void);
	virtual void SetMove(void);

	// 座標情報取得
	const VECTOR2 Pos()const;
	// サイズ情報取得
	const int Size()const;

protected:
	VECTOR2 _pos;		// 座標
	int _size;			// キャラの大きさ(半径)
	double speed;		// 移動速度
	int _life;			// 機体の残機

};

