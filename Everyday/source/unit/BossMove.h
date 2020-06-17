#pragma once
#include <array>
#include <vector>
#include "Enemy.h"
#include "../common/Vector2.h"

enum ATTACK_TYPE
{
	WAY,		// 放射弾
	RUSH,		// 突進攻撃
	MAX
};

class BossMove
{
public:
	BossMove();
	BossMove(const VECTOR2 &pos,float size,float angle,float speed);
	~BossMove();

	const VECTOR2 GetPos(void) { return _pos; };
	const float GetSize(void) { return _size; };
	const float GetAngle(void) { return _angle; };
	void SetMove(const VECTOR2 &playerPos);

private:
	void Init(void);
	void Way(void);
	void Rush(void);


	VECTOR2 _pos;		// 座標
	VECTOR2 _vel;
	float _size;		// 大きさ
	float _angle;		// 向き
	float _shotAngle;
	float _speed;		// スピード
	float _defSpeed;	// デフォルトのスピード
	int _rotateCnt;
	VECTOR2 _playerPos;	// プレイヤーの座標
	VECTOR2 _targetPos; // 移動先の座標
	void (BossMove::*move)(void);	// メンバ関数ポインタ
	std::array<int, static_cast<int>(ATTACK_TYPE::MAX)> _attackCnt;	// 攻撃頻度
	std::array<VECTOR2, 5> _movePos;
	std::vector<Shared_Obj> _shot;
	std::array<VECTOR2, 4> _batteryPos;
};

