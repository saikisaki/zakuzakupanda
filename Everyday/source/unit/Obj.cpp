#include "Obj.h"


Obj::Obj()
{
}

Obj::~Obj()
{
}

void Obj::Draw(void)
{
}

void Obj::SetMove(void)
{
}

const STATE Obj::State(void)
{
	return _animKey;
}

void Obj::State(const STATE state)
{
	if (_animKey != state)
	{
		_animCnt = 0;
	}

	_animKey = state;
}

const int Obj::Life(void)
{
	return _life;
}

void Obj::Life(const int life)
{
	_life = life;
}

const VECTOR2 Obj::Pos() const
{
	return _pos;
}

const int Obj::Size() const
{
	return _size;
}

bool Obj::SetAnim(const STATE key, AnimVector & data)
{
	return _animMap.try_emplace(key, std::move(data)).second;
}
