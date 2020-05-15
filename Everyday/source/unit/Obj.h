#pragma once
#include <memory>
#include <map>
#include <vector>
#include "../common/Vector2.h"

enum class STATE	// �L�����̌��݂̏��
{
	NORMAL,		// �ʏ�
	EX,			// ����
	BOMB,		// ���j
	DEATH,		// ��
	INVINCIBLE, // ���G
	MAX
};

enum class UNIT
{
	PLAYER,		// �v���C���[���j�b�g
	ENEMY,		// �G
	MAX
};

class Obj;
using Shared_Obj = std::shared_ptr<Obj>;
using AnimVector = std::vector<std::pair<int, int>>;		// �摜�n���h�� �\���t���[����

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
	// ���W���擾
	const VECTOR2 Pos()const;
	// �T�C�Y���擾
	const int Size()const;

protected:
	bool SetAnim(const STATE key, AnimVector &data);
	VECTOR2 _pos;		// ���W
	int _size;			// �L�����̑傫��(���a)
	int _speed;			// �ړ����x
	int _life;			// �@�̂̎c�@
	int _animCnt;		// �A�j���[�V�����J�E���^�[
	STATE _animKey;		// �A�j���[�V�����^�C�v
	int _animFram;		// �A�j���[�V�����̃t���[����
	std::map<STATE, const AnimVector> _animMap;		// �A�j���[�V���������i�[���Ă���map

};

