#pragma once
#include <memory>
#include <map>
#include <vector>
#include "../common/Vector2.h"

enum class STATE	// キャラの現在の状態
{
	NORMAL,		// 通常
	EX,			// 特殊
	BOMB,		// 爆破
	DEATH,		// 死
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
using AnimVector = std::vector<std::pair<int, int>>;		// 画像ハンドル 表示フレーム数

class Obj
{
public:
	Obj();
	~Obj();
	virtual UNIT GetUnit(void) = 0;
	virtual void Draw(void);
	virtual void SetMove(void);
	const STATE State(void);
	void State(const STATE state);
	// 座標情報取得
	const VECTOR2 Pos()const;
	// サイズ情報取得
	const int Size()const;

protected:
	bool SetAnim(const STATE key, AnimVector &data);
	VECTOR2 _pos;		// 座標
	int _size;			// キャラの大きさ(半径)
	int _speed;			// 移動速度
	int _life;			// 機体の残機
	int _animCnt;		// アニメーションカウンター
	STATE _animKey;		// アニメーションタイプ
	int _animFram;		// アニメーションのフレーム数
	std::map<STATE, const AnimVector> _animMap;		// アニメーション情報を格納しているmap

};

