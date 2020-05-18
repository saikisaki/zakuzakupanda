#pragma once
#include "Obj.h"
class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(const VECTOR2 &pos, const int &size,const VECTOR2 &playerPos);
	~Enemy();

	UNIT GetUnit(void) override;
	void SetMove(void) override;
	void Draw(void) override;
private:
	void Init(const VECTOR2 &playerPos);
	bool Explosion(void);
	
	VECTOR2 _vel;
};

