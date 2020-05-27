#pragma once
#include <memory>
#include <map>
#include <vector>
#include "../common/Vector2.h"

enum class STATE	// キャラの現在の状態
{
	DEATH,		// 死
	NORMAL,		// 通常
	EX,			// 特殊
	BOMB,		// 爆破
	INVINCIBLE, // 無敵
	MAX
};

enum class UNIT
{
	PLAYER,		// プレイヤーユニット
	ENEMY,		// 敵
	ITEM,		// アイテム
	MAX
};

class Obj;
using Shared_Obj = std::shared_ptr<Obj>;
using AnimVector = std::vector<std::pair<int, int>>;		// 画像ハンドル 表示フレーム数

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual UNIT GetUnit(void) = 0;
	virtual void Draw(void);
	virtual void SetMove(Shared_Obj &player);
	const STATE State(void);
	void State(const STATE &state);
	const int Life(void);
	void Life(const int life);
	const int BombTag(void) { return _bombTag; };
	void BombTag(const int &tag);
	const int BlastRange(void);
	void BlastRange(const int blast);

	// 座標情報取得
	const VECTOR2 Pos()const;
	// サイズ情報取得
	const int Size()const;

protected:
	bool SetAnim(const STATE key, AnimVector &data);
	VECTOR2 _pos;		// 座標
	float _size;			// キャラの大きさ(半径)
	int _speed;			// 移動速度
	int _life;			// 機体の残機
	int _animCnt;		// アニメーションカウンター
	int _defSize;		// デフォルトの機体サイズ
	STATE _animKey;		// アニメーションタイプ
	int _animFram;		// アニメーションのフレーム数
	int _blastRange;	// 最大爆風範囲
	std::map<STATE, const AnimVector> _animMap;		// アニメーション情報を格納しているmap
	int _bombTag;		// 自機のタグ
};

