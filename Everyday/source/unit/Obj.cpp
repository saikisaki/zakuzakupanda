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
	_animKey = state;
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
