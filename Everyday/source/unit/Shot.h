#pragma once
#include "Obj.h"

class Shot :
	public Obj
{
public:
	Shot();
	Shot(const VECTOR2 &pos,const VECTOR2 &bossPos,const float speed,const float angle,const float size);
	~Shot();

	UNIT GetUnit(void) override;
	void SetMove(Shared_Obj &player) override;
	void Draw(void) override;
private:
	void Init(void);
	
	float _angle;
	VECTOR2 _bossPos;
	VECTOR2 _vel;
};

