#pragma once

class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(float x, float y);
	~VECTOR2();

	float x;
	float y;

	// γόZq
	VECTOR2& operator = (const VECTOR2& vec);

	// LXgZq
	operator bool() { return this->x == 0 && this->y == 0; }

	// Y¦Zq
	float& operator[](float i);

	// δrZq
	bool operator==(const VECTOR2& vec) const;
	bool operator!=(const VECTOR2& vec) const;
	bool operator<(int k) const;

	// PZq
	VECTOR2& operator += (const VECTOR2& vec);
	VECTOR2& operator -= (const VECTOR2& vec);
	VECTOR2& operator *= (float k);
	VECTOR2& operator /= (float k);
	VECTOR2  operator+() const;
	VECTOR2  operator-() const;
};

// ΝήΈΔΩΜZ
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

//ΰΟπΤ·
float Dot(const VECTOR2& va, const VECTOR2& vb);

//OΟπΤ·
float Cross(const VECTOR2& va, const VECTOR2& vb);

//ΰΟZq
float operator*(const VECTOR2& va, const VECTOR2& vb);
