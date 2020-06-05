#include <time.h>
#include <cmath>
#include "BossMove.h"
#include "../Mng/SceneMng.h"
#include "Shot.h"
#include "../Mng/SceneMng.h"

#define PI    3.141592

BossMove::BossMove()
{
	Init();
}

BossMove::BossMove(const VECTOR2 & pos, const float  size, const float angle, const float speed)
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
	_rotateCnt = 0;
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
	if (lpSceneMng.GetFrame() % 60 == 0)
	{
		for (auto &shot : _batteryPos)
		{
			_shot.emplace_back(std::make_shared<Shot>(shot,_pos, 2, 0, 10));
		}
	}
}

void BossMove::Rush(void)
{
}

void BossMove::SetMove(const VECTOR2 &playerPos)
{
	float distance = hypot(_targetPos.y - _pos.y, _targetPos.x - _pos.x);

	float angle = 0;
	int arrayCnt = 0;
	for (auto &shot : _batteryPos)
	{
		shot = _pos;
		angle = PI / 180 * (90 * arrayCnt + 45 + _rotateCnt);
		shot.x += cos(angle) * _size;
		shot.y += sin(angle) * _size;
		arrayCnt++;
	}

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

		switch (rand() % 2)
		{
		case ATTACK_TYPE::WAY:
			move = &BossMove::Way;
			break;
		case ATTACK_TYPE::RUSH:
			move = &BossMove::Rush;
			break;
		default:
			break;
		}

		_angle = atan2f(_targetPos.y - _pos.y, _targetPos.x - _pos.x);
		_vel.x = cos(_angle) * _speed;
		_vel.y = sin(_angle) * _speed;
	}

	_pos += _vel;

	_rotateCnt++;

	(this->*move)();
}
