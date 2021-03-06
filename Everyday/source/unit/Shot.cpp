#include <cmath>
#include "DxLib.h"
#include "Shot.h"
#include "../Mng/ImageMng.h"


Shot::Shot()
{
	Init();
}

Shot::Shot(const VECTOR2 & pos, const VECTOR2 &bossPos,float  speed,float  angle,float  size)
{
	_pos = pos;
	_bossPos = bossPos;
	_speed = speed;
	_angle = angle;
	_size = size;
	Init();
}

void Shot::Init(void)
{
	_angle = atan2f(_pos.y - _bossPos.y, _pos.x - _bossPos.x);
	_vel.x = cos(_angle) * _speed;
	_vel.y = sin(_angle) * _speed;
}

Shot::~Shot()
{
}

UNIT Shot::GetUnit(void)
{
	return UNIT::SHOT;
}

void Shot::SetMove(Shared_Obj & player)
{
	_pos += _vel;
}

void Shot::Draw(void)
{
	DrawRotaGraph(_pos.x,_pos.y,0,0,lpImageMng.GetID("image/shot.png")[0],true,false);
}
