#pragma once
#include <array>
#include "../common/VECTOR2.h"

class Referee
{
public:
	Referee();
	Referee(const VECTOR2 &pointPos,const VECTOR2 &timePos);
	~Referee();

	const int Point(void);
	void Point(const int &point);
	bool TimeUpdate(void);
	void Draw(void);
private:
	void Init(void);
	VECTOR2 _pointPos;
	VECTOR2 _timePos;
	VECTOR2 _size;
	int _time;
	std::array<int,5> _pointArray;
	std::array<int, 3> _timeArray;
	std::array<int, 10> _numArray;
};

