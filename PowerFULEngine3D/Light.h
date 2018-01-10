#pragma once
class Light
{
public:
	Light();
	void ambientLight();
	void pointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec);
	~Light();
};

