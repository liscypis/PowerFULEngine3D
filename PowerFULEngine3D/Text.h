#pragma once
class Text
{
public:
	Text();
	~Text();
	void setOrthographicProjection();
	void restorePerspectiveProjection();
	void renderSpacedBitmapString(float x, float y, int spacing, char * string);
};

