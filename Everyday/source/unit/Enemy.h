#pragma once
#include "Obj.h"

class BossMove;

enum class ENEM_TYPE
{
	BOSS,
	ZAKO,
	MAX
};

class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(const VECTOR2 &pos, const int &size,const VECTOR2 &playerPos,const ENEM_TYPE &type);
	~Enemy();

	UNIT GetUnit(void) override;
	void SetMove(Shared_Obj &player) override;
	void Draw(void) override;
private:
	void Init(const VECTOR2 &playerPos);
	bool Explosion(void);
	bool OffScreen(void);
	bool DrawMagic(void);


	VECTOR2 _vel;
	VECTOR2 _startPos;
	float _angle;
	ENEM_TYPE _type;
	int _rotateCnt;
	float _circleSize;
	std::unique_ptr<BossMove> _bossData;
};

