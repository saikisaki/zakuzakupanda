#include <cmath>
#include "DxLib.h"
#include "Referee.h"
#include "../Mng/ImageMng.h"
#include "../Mng/SceneMng.h"

Referee::Referee()
{
	Init();
}

Referee::Referee(const VECTOR2 & pos, const VECTOR2 &timePos)
{
	_pointPos = pos;
	_timePos = timePos;
	Init();
}

Referee::~Referee()
{
}

void Referee::Init(void)
{
	_size = { 16,32 };
	_pointArray = { 0,0,0,0,0 };
	_timeArray  = {0,0,0};
	lpImageMng.GetID("����", "image/number.png", { _size.x,_size.y }, { 13,1 });
	_numArray = 
	{
		IMAGE_ID("����")[0],
		IMAGE_ID("����")[1],
		IMAGE_ID("����")[2],
		IMAGE_ID("����")[3],
		IMAGE_ID("����")[4],
		IMAGE_ID("����")[5],
		IMAGE_ID("����")[6],
		IMAGE_ID("����")[7],
		IMAGE_ID("����")[8],
		IMAGE_ID("����")[9]
	};
}

bool Referee::TimeUpdate(void)
{
	int time = lpSceneMng.GetFrame() / 60;

	if (_time > 180)
	{
		return false;
	}

	for (auto &num : _timeArray)
	{
		if (time == 0)
		{
			break;
		}
		num = time % 10;
		time /= 10;
	}

	return true;
}

void Referee::BombCnt(const BombVec & bomb)
{
	_bombCnt = bomb;
}

const int Referee::Point(void)
{
	int point = 0;
	int count = 0;
	for (auto &p : _pointArray)
	{
		if (count != 0)
		{
			point += p * std::pow(10, count);
		}
		else
		{
			point += p;
		}
		count++;
	}
	
	return point;
}

void Referee::Point(const int & p)
{
	int point = p;

	// �J���X�g����
	if (point >= 1000)
	{
		point = 999;
	}

	for (auto &num : _pointArray)
	{
		if (point == 0)
		{
			break;
		}
		num = point % 10;
		point /= 10;
	}
}

void Referee::Draw(void)
{
	int digits = 1;
	for (auto &point:_pointArray)
	{
		DrawGraph(_pointPos.x - _size.x * digits, _pointPos.y, _numArray[point], true);
		digits++;
	}

	digits = 1;
	for (auto &time : _timeArray)
	{
		DrawGraph(_timePos.x - _size.x * digits, _timePos.y, _numArray[time], true);
		digits++;
	}

	for (auto &bomb : _bombCnt)
	{
		for (auto &bNum : bomb)
		{
			DrawFormatString(bNum.second.x, bNum.second.y, 0xaaaaaa, "%d", bNum.first);
		}
	}
}
