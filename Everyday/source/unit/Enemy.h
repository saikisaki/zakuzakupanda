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
	void SetMove(Shared_Obj &player) override;
	void Draw(void) override;
private:
	void Init(const VECTOR2 &playerPos);
	bool Explosion(void);
	bool OffScreen();
	
	VECTOR2 _vel;
	VECTOR2 _startPos;
	float _angle;
};

