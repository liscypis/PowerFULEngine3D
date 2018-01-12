#include "Text.h"
#include "Window.h"
#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"

Text::Text()
{
}


Text::~Text()
{
}

void Text::setOrthographicProjection() {
	int h = Window::getHeight();
	int w = Window::getWidth();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Text::restorePerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void Text::renderSpacedBitmapString(float x, float y, int spacing, char * string)
{
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		x1 = x1 + glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *c) + spacing;
	}
	glPopMatrix();
	restorePerspectiveProjection();
}