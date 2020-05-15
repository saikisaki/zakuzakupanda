#include "DxLib.h"
#include "Enemy.h"
#include "../Mng/ImageMng.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const VECTOR2 & pos, const int & size)
{
	_pos = pos;
	_size = size;
	Init();
}


Enemy::~Enemy()
{
}

void Enemy::Init(void)
{
	_animKey = STATE::NORMAL;
	_animFram = 0;
	_animCnt = 0;

	lpImageMng.GetID("ìG", "image/enemy.png", { 75,75 }, { 4,3 });

	AnimVector data;

	data.reserve(4);
	data.emplace_back(IMAGE_ID("ìG")[0], 20);
	data.emplace_back(IMAGE_ID("ìG")[4], 40);
	data.emplace_back(IMAGE_ID("ìG")[7], 60);
	data.emplace_back(IMAGE_ID("ìG")[10], 80);

	SetAnim(STATE::NORMAL, data);
}

UNIT Enemy::GetUnit(void)
{
	return UNIT::ENEMY;
}

void Enemy::SetMove(void)
{
	_pos.y += 5;
}

void Enemy::Draw(void)
{
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
		DrawRotaGraph(static_cast<int>(_pos.x), static_cast<int>(_pos.y), 0.7, 0, _animMap[_animKey][_animFram].first, true, false);
	}

	//_DbgDrawBox(_pos.x, _pos.y, _pos.x + _size.x, _pos.y + _size.y, 0xff0000, 1);
	//_DbgDrawString(_pos.x, _pos.y, "å©Ç¶Ç‹Ç∑Ç©ÅH", 0xff00ff);
	_animCnt++;
}
