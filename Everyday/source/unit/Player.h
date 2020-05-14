#pragma once
#include "Obj.h"

class Player :
	public Obj
{
public:
	Player();
	Player(const VECTOR2& pos, const int& size);
	~Player();

	UNIT GetUnit(void) override;
	void SetMove(void) override;
	void Draw(void) override;

private:
	void Init(void);
};

