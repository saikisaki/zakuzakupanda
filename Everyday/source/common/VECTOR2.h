#pragma once

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(float x, float y);
	~VECTOR2();

	float x;
	float y;

	// ‘ã“ü‰‰ŽZŽq
	VECTOR2& operator = (const VECTOR2& vec);

	// ƒLƒƒƒXƒg‰‰ŽZŽq
	operator bool() { return this->x == 0 && this->y == 0; }

	// “Y‚¦Žš‰‰ŽZŽq
	float& operator[](float i);

	// ”äŠr‰‰ŽZŽq
	bool operator==(const VECTOR2& vec) const;
	bool operator!=(const VECTOR2& vec) const;
	bool operator<(int k) const;

	// ’P€‰‰ŽZŽq
	VECTOR2& operator += (const VECTOR2& vec);
	VECTOR2& operator -= (const VECTOR2& vec);
	VECTOR2& operator *= (float k);
	VECTOR2& operator /= (float k);
	VECTOR2  operator+() const;
	VECTOR2  operator-() const;
};

// ÍÞ¸ÄÙ‚Ì‰‰ŽZ
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

//“àÏ‚ð•Ô‚·
float Dot(const VECTOR2& va, const VECTOR2& vb);

//ŠOÏ‚ð•Ô‚·
float Cross(const VECTOR2& va, const VECTOR2& vb);

//“àÏ‰‰ŽZŽq
float operator*(const VECTOR2& va, const VECTOR2& vb);
