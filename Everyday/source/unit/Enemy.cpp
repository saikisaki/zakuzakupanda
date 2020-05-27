#include <cmath>
#include "DxLib.h"
#include "Enemy.h"
#include "../Mng/ImageMng.h"
#include "../Mng/SceneMng.h"

#define PI    3.141592

Enemy::Enemy()
{
}

Enemy::Enemy(const VECTOR2 &pos, const int &size,const VECTOR2 &playerPos, const ENEM_TYPE &type)
{
	_pos = pos;
	_size = size;
	_type = type;
	Init(playerPos);
}


Enemy::~Enemy()
{
}

void Enemy::Init(const VECTOR2 &playerPos)
{
	
	_animFram = 0;
	_animCnt = 0;
	_speed = 3;
	_angle = atan2f(playerPos.y - _pos.y, playerPos.x - _pos.x);
	_vel.x = cos(_angle) * _speed;
	_vel.y = sin(_angle) * _speed;
	_blastRange = 100;
	_bombTag = 0;
	_startPos = _pos;
	_rotateCnt = 0;
	_circleSize = 0;

	if (_type == ENEM_TYPE::ZAKO)
	{
		_animKey = STATE::NORMAL;
		lpImageMng.GetID("ザコ", "image/enemy.png", { 48,48 }, { 4,3 });
		AnimVector data;
		data.reserve(4);
		data.emplace_back(IMAGE_ID("ザコ")[0], 10);
		data.emplace_back(IMAGE_ID("ザコ")[1], 20);
		data.emplace_back(IMAGE_ID("ザコ")[2], 30);
		data.emplace_back(IMAGE_ID("ザコ")[3], 40);

		SetAnim(STATE::NORMAL, data);
	}
	else if (_type == ENEM_TYPE::BOSS)
	{
		_animKey = STATE::INVINCIBLE;
		lpImageMng.GetID("ボス", "image/boss.png");
		AnimVector data;
		data.reserve(1);
		data.emplace_back(IMAGE_ID("ボス")[0], 40);
		SetAnim(STATE::NORMAL, data);
	}
	else
	{
		// 何もしない
	}
}

void Enemy::SetMove(Shared_Obj &player)
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

	if (_type == ENEM_TYPE::ZAKO)
	{
		_pos += _vel;
	}

	if (OffScreen())
	{
		State(STATE::DEATH);
	}
}

bool Enemy::Explosion(void)
{
	_size = _animCnt / 2;

	if (_size >= _blastRange)
	{
		_size = _defSize;
		return false;
	}

	return true;
}

UNIT Enemy::GetUnit(void)
{
	return UNIT::ENEMY;
}

bool Enemy::OffScreen(void)
{
	if (hypot(_pos.x - _startPos.x, _pos.y - _startPos.y) >= 2000)
	{
		return true;
	}

	return false;
}

bool Enemy::DrawMagic(void)
{
	int rotate = PI / 180 * (_rotateCnt * 22);

	if (_circleSize >= 1)
	{
		_circleSize = 1;
		_animKey = STATE::NORMAL;
	}
	else
	{
		_circleSize = _rotateCnt * 0.005;
	}

	SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
	SetDrawBright(200, 0, 200);
	DrawRotaGraph(_pos.x,_pos.y, _circleSize, rotate, lpImageMng.GetID("image/magic.png")[0],true);
	SetDrawBright(255, 255, 255);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	_rotateCnt++;
	return true;
}

void Enemy::Draw(void)
{
	if (_type == ENEM_TYPE::BOSS)
	{
		DrawMagic();
	}
	
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
		DrawRotaGraph(static_cast<int>(_pos.x), static_cast<int>(_pos.y), 1.5, _angle, _animMap[_animKey][_animFram].first, true, false);
	}

	_animCnt++;
}
