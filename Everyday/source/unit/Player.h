#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	Player(const VECTOR2& pos, const int& size);
	~Player();
};

