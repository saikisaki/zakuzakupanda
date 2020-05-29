#include <time.h>
#include <cmath>
#include "BossMove.h"
#include "../Mng/SceneMng.h"
#include "Shot.h"

#define PI    3.141592

BossMove::BossMove()
{
	Init();
}

BossMove::BossMove(const VECTOR2 & pos, const float & size, const float &angle, const float &speed)
{
	_pos = pos;
	_size = size;
	_angle = angle;
	_defSpeed = speed;
	Init();
}


BossMove::~BossMove()
{
}

void BossMove::Init(void)
{
	srand((unsigned int)time(NULL));
	_speed = _defSpeed;
	_attackCnt = {60,30};
	_movePos = 
	{
		VECTOR2(lpSceneMng.GetScreenSize().x / 4,lpSceneMng.GetScreenSize().y / 4),
		VECTOR2(lpSceneMng.GetScreenSize().x * 3 / 4,lpSceneMng.GetScreenSize().y / 4),
		VECTOR2(lpSceneMng.GetScreenSize().x / 4,lpSceneMng.GetScreenSize().y * 3 / 4),
		VECTOR2(lpSceneMng.GetScreenSize().x * 3 / 4,lpSceneMng.GetScreenSize().y * 3 / 4),
		VECTOR2(lpSceneMng.GetScreenSize().x / 2,lpSceneMng.GetScreenSize().y / 2)
	};

	_targetPos = _movePos[rand() % _movePos.size()];
	move = &BossMove::Way;
	_angle = atan2f(_targetPos.y - _pos.y, _targetPos.x - _pos.x);
	_vel.x = cos(_angle) * _speed;
	_vel.y = sin(_angle) * _speed;
}

void BossMove::Way(void)
{
	float angle = 0;
	VECTOR2 shotPos;
	for (int s = 0; s < 3; s++)
	{
		angle = PI / 180 * (90 * s + 45);
		shotPos.x = cos(angle) * _size;
		shotPos.y = sin(angle) * _size;

	}

	
}

void BossMove::Rush(void)
{
}

void BossMove::SetMove(const VECTOR2 &playerPos)
{
	float distance = hypot(_targetPos.y - _pos.y, _targetPos.x - _pos.x);

	if (distance < _speed)
	{
		if (move == &BossMove::Rush)
		{
			_targetPos = playerPos;
			_speed = _defSpeed * 2;
		}
		else
		{
			_playerPos = playerPos;
			_targetPos = _movePos[rand() % _movePos.size()];
			_speed = _defSpeed;
		}

		_angle = atan2f(_targetPos.y - _pos.y, _targetPos.x - _pos.x);
		_vel.x = cos(_angle) * _speed;
		_vel.y = sin(_angle) * _speed;
	}

	_pos += _vel;

	(this->*move)();
}
