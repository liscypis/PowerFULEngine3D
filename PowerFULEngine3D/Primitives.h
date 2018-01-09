#pragma once
class Primitives
{
public:
	Primitives();
	void triangle(const float(&x)[3], const float(&y)[3], const float(&z)[3], const float(&rgb)[3]);
	void terrain(const float(&x)[3], const float(&y)[3], const float(&z)[3], const float(&d)[3], const float(&rgb)[3]);
	void drawSnowMan();
	~Primitives();
};

