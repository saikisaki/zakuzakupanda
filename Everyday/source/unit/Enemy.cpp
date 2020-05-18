#include <cmath>
#include "DxLib.h"
#include "Enemy.h"
#include "../Mng/ImageMng.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const VECTOR2 &pos, const int &size,const VECTOR2 &playerPos)
{
	_pos = pos;
	_size = size;
	Init(playerPos);
}


Enemy::~Enemy()
{
}

void Enemy::Init(const VECTOR2 &playerPos)
{
	_animKey = STATE::NORMAL;
	_animFram = 0;
	_animCnt = 0;
	_speed = 3;
	float angle = atan2f(playerPos.y - _pos.y, playerPos.x - _pos.x);
	_vel.x = cos(angle) * _speed;
	_vel.y = sin(angle) * _speed;

	lpImageMng.GetID("“G", "image/enemy2.png", { 48,48 }, { 4,3 });

	AnimVector data;

	data.reserve(4);
	data.emplace_back(IMAGE_ID("“G")[0], 10);
	data.emplace_back(IMAGE_ID("“G")[1], 20);
	data.emplace_back(IMAGE_ID("“G")[2], 30);
	data.emplace_back(IMAGE_ID("“G")[3], 40);

	SetAnim(STATE::NORMAL, data);
}

UNIT Enemy::GetUnit(void)
{
	return UNIT::ENEMY;
}

void Enemy::SetMove(void)
{
	if (_animKey == STATE::BOMB)
	{
		if (!Explosion())
		{
			State(STATE::DEATH);
		}
		else
		{
			return;
		}
	}

	_pos += _vel;
}

bool Enemy::Explosion(void)
{
	_size = _animCnt / 3;

	if (_size >= 100)
	{
		_size = _defSize;
		return false;
	}

	return true;
}


void Enemy::Draw(void)
{

	if (_animKey == STATE::BOMB)
	{
		DrawCircle(_pos.x, _pos.y, _size, 0xff0000, 0);
		_animCnt++;
	}

	if (_animMap.find(_animKey) == _animMap.end())
	{
		return;
	}

	if (_animMap[_animKey].size() <= _animFram)
	{
		return;
	}

	if (_animCnt >= _animMap[_animKey][_animFram].second)
	{
		_animFram++;
		if (_animFram >= _animMap[_animKey].size())
		{
			_animFram = 0;
			_animCnt = 0;
		}
	}

	if (_animCnt <= _animMap[_animKey][_animFram].second)
	{
		DrawRotaGraph(static_cast<int>(_pos.x), static_cast<int>(_pos.y), 1.5, 0, _animMap[_animKey][_animFram].first, true, false);
	}
		
	
	else
	{
		// ‰½‚à‚µ‚È‚¢
	}

	_animCnt++;
}
