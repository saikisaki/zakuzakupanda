#pragma once
#include <array>
#include <vector>
#include "../common/VECTOR2.h"
#include "../scene/GameScene.h"


class Referee
{
public:
	Referee();
	Referee(const VECTOR2 &pointPos,const VECTOR2 &timePos);
	~Referee();

	const int Point(void);
	void Point(int point);
	bool TimeUpdate(void);
	void BombCnt(const BombVec &bomb);
	void Draw(void);
private:
	void Init(void);
	VECTOR2 _pointPos;
	VECTOR2 _timePos;
	VECTOR2 _size;
	int _time;				// �o�ߎ���
	
	std::array<int,5> _pointArray;			// �|�C���g�J�E���g�A5����
	std::array<int, 3> _timeArray;			// ���ԃJ�E���g�A100�̌��A10�̌��A1�̌�
	std::array<int, 10> _numArray;			// �J�E���g�\�L�p�z��
	BombVec _bombCnt;
};

