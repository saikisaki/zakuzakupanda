#include "VECTOR2.h"

VECTOR2::VECTOR2()
{
}

VECTOR2::VECTOR2(float x, float y)
{
	this->x = x;
	this->y = y;
}

VECTOR2::~VECTOR2()
{
}


VECTOR2 & VECTOR2::operator=(const VECTOR2 & vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return (*this);
}

float & VECTOR2::operator[](float i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

bool VECTOR2::operator==(const VECTOR2 & vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool VECTOR2::operator!=(const VECTOR2 & vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}

bool VECTOR2::operator<(int k) const
{
	return (this->x < k) && (this->y < k);
}

VECTOR2 & VECTOR2::operator+=(const VECTOR2 & vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return (*this);
}

VECTOR2 & VECTOR2::operator-=(const VECTOR2 & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return (*this);
}

VECTOR2 & VECTOR2::operator*=(float k)
{
	this->x *= k;
	this->y *= k;
	return (*this);
}

VECTOR2 & VECTOR2::operator/=(float k)
{
	// 注:ｶﾞｰﾄﾞ処理が必要な場合がある

	this->x /= k;
	this->y /= k;
	return (*this);
}

VECTOR2 VECTOR2::operator+() const
{
	return (*this);
}

VECTOR2 VECTOR2::operator-() const
{
	return VECTOR2(-this->x, -this->y);
}

VECTOR2 operator+(const VECTOR2 & u, int v)
{
	VECTOR2 vec;
	vec.x = u.x + v;
	vec.y = u.y + v;

	return vec;
}

VECTOR2 operator-(const VECTOR2 & u, int v)
{
	VECTOR2 vec;
	vec.x = u.x - v;
	vec.y = u.y - v;

	return vec;
}

VECTOR2 operator+(const VECTOR2 & u, const VECTOR2 & v)
{
	VECTOR2 vec;
	vec.x = u.x + v.x;
	vec.y = u.y + v.y;

	return vec;
}

VECTOR2 operator-(const VECTOR2 & u, const VECTOR2 & v)
{
	VECTOR2 vec;
	vec.x = u.x - v.x;
	vec.y = u.y - v.y;

	return vec;
}

VECTOR2 operator*(const VECTOR2 & u, int v)
{
	VECTOR2 vec;
	vec.x = u.x * v;
	vec.y = u.y * v;

	return vec;
}

VECTOR2 operator*(int u, const VECTOR2 & v)
{
	VECTOR2 vec;
	vec.x = u * v.x;
	vec.y = u * v.y;

	return vec;
}

VECTOR2 operator/(const VECTOR2 & u, int v)
{
	VECTOR2 vec;
	vec.x = u.x / v;
	vec.y = u.y / v;

	return vec;
}

VECTOR2 operator/(const VECTOR2 & u, const VECTOR2 & v)
{
	VECTOR2 vec;
	vec.x = u.x / v.x;
	vec.y = u.y / v.y;

	return vec;
}



//内積を返す
float Dot(const VECTOR2& va, const VECTOR2& vb)
{
	return va.x*vb.x + va.y*vb.y;
}

//外積を返す
float Cross(const VECTOR2& va, const VECTOR2& vb)
{
	return va.x*vb.y - vb.x*va.y;
}

//内積演算子
float operator*(const VECTOR2& va, const VECTOR2& vb)
{
	return Dot(va, vb);
}
