#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(const VECTOR2& pos, const int& size);
	~Enemy();

	UNIT GetUnit(void) override;
	void SetMove(void) override;
	void Draw(void) override;
private:
	void Init(void);
};

