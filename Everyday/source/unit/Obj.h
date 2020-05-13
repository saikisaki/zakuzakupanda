#pragma once
#include <memory>
#include "../common/Vector2.h"

enum class STATE	// �L�����̌��݂̏��
{
	NORMAL,		// �ʏ�
	EX,			// ����
	DEATH,		// ���j
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

class Obj
{
public:
	Obj();
	~Obj();
	virtual void Draw(void);
	virtual void SetMove(void);

	// ���W���擾
	const VECTOR2 Pos()const;
	// �T�C�Y���擾
	const int Size()const;

protected:
	VECTOR2 _pos;		// ���W
	int _size;			// �L�����̑傫��(���a)
	double speed;		// �ړ����x
	int _life;			// �@�̂̎c�@

};

