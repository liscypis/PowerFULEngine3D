#pragma once
class Primitives
{
public:
	Primitives();
	void triangle(const float(&a)[3], const float(&b)[3], const float(&c)[3], const float(&rgb)[3]);
	void terrain(const float(&a)[3], const float(&b)[3], const float(&c)[3], const float(&d)[3], const float(&rgb)[3]);
	void normalTerrain(const float(&a)[3], const float(&b)[3], const float(&c)[3], const float(&d)[3], const float(&rgb)[3]);
	void drawSphere(const float radius, const float alpha);
	void line(const float(&a)[3], const float(&b)[3], const float(&rgb)[3]);
	void drawSnowMan();
	void solidCube(int size);
	void wall(int size);
	~Primitives();
};

