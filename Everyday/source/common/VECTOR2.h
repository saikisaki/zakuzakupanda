#pragma once

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();

	int x;
	int y;

	// ������Z�q
	VECTOR2& operator = (const VECTOR2& vec);

	// �L���X�g���Z�q
	operator bool() { return this->x == 0 && this->y == 0; }

	// �Y�������Z�q
	int& operator[](int i);

	// ��r���Z�q
	bool operator==(const VECTOR2& vec) const;
	bool operator!=(const VECTOR2& vec) const;
	bool operator<(int k) const;

	// �P�����Z�q
	VECTOR2& operator += (const VECTOR2& vec);
	VECTOR2& operator -= (const VECTOR2& vec);
	VECTOR2& operator *= (int k);
	VECTOR2& operator /= (int k);
	VECTOR2  operator+() const;
	VECTOR2  operator-() const;
};

// �޸�ق̉��Z
// VECTOR2 + int
VECTOR2 operator+(const VECTOR2 &u, int v);

// VECTOR2 - int
VECTOR2 operator-(const VECTOR2 &u, int v);

// VECTOR2 + VECTOR2
VECTOR2 operator+(const VECTOR2 &u, const VECTOR2 &v);

// VECTOR2 - VECTOR2
VECTOR2 operator-(const VECTOR2 &u, const VECTOR2 &v);

// VECTOR2 * int
VECTOR2 operator*(const VECTOR2 &u, int v);

// int * VECTOR2
VECTOR2 operator*(int u, const VECTOR2 &v);

// VECTOR2 / int
VECTOR2 operator/(const VECTOR2 &u, int v);

// VECTOR2 % VECTOR2
VECTOR2 operator/(const VECTOR2 &u, const VECTOR2 &v);

// VECTOR2 % int
VECTOR2 operator%(const VECTOR2 &u, int v);

// VECTOR2 % VECTOR2
VECTOR2 operator%(const VECTOR2 &u, const VECTOR2 &v);

struct Rect
{
	Rect() : startPos({0, 0}), endPos({0, 0}) {}
	Rect(VECTOR2 start, VECTOR2 end) : startPos(start), endPos(end) {}

	VECTOR2 startPos;
	VECTOR2 endPos;
};

