#include "Primitives.h"



Primitives::Primitives()
{
}

void Primitives::triangle() {
	glBegin(GL_TRIANGLES);
		glVertex3f(-2, -2, -5.0);
		glVertex3f(2, 0.0, -5.0);
		glVertex3f(0.0, 2, -5.0);
	glEnd();
}

Primitives::~Primitives()
{
}
