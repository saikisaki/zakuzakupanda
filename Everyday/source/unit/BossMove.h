#pragma once
#include <array>
#include <vector>
#include "Enemy.h"
#include "../common/Vector2.h"

enum ATTACK_TYPE
{
	WAY,		// ���˒e
	RUSH,		// �ːi�U��
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


	VECTOR2 _pos;		// ���W
	VECTOR2 _vel;
	float _size;		// �傫��
	float _angle;		// ����
	float _shotAngle;
	float _speed;		// �X�s�[�h
	float _defSpeed;	// �f�t�H���g�̃X�s�[�h
	int _rotateCnt;
	VECTOR2 _playerPos;	// �v���C���[�̍��W
	VECTOR2 _targetPos; // �ړ���̍��W
	void (BossMove::*move)(void);	// �����o�֐��|�C���^
	std::array<int, static_cast<int>(ATTACK_TYPE::MAX)> _attackCnt;	// �U���p�x
	std::array<VECTOR2, 5> _movePos;
	std::vector<Shared_Obj> _shot;
	std::array<VECTOR2, 4> _batteryPos;
};

