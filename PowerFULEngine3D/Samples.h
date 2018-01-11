#pragma once
class Samples
{
public:
	Samples();
	void enableUserInputs();
	void enableLightning();
	void drawSampleObjects();
	void setOrthographicProjection();
	void restorePerspectiveProjection();
	void renderSpacedBitmapString(float x, float y, int spacing, void* font, char* string);
	~Samples();
};

