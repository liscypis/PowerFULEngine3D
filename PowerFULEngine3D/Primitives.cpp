#include "Primitives.h"
#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"


Primitives::Primitives()
{
}


void Primitives::triangle(const float(&a)[3], const float(&b)[3], const float(&c)[3], const float(&rgb)[3]) {
	glBegin(GL_TRIANGLES);
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glVertex3f(a[0], a[1], a[2]);
	glVertex3f(b[0], b[1], b[2]);
	glVertex3f(c[0], c[1], c[2]);
	glEnd();
}

void Primitives::line(const float(&a)[3], const float(&b)[3], const float(&rgb)[3]) {
	glBegin(GL_LINES);
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glVertex3f(a[0], a[1], a[2]);
	glVertex3f(b[0], b[1], b[2]);
	glEnd();
}

void Primitives::terrain(const float(&a)[3], const float(&b)[3], const float(&c)[3], const float(&d)[3], const float(&rgb)[3]) {
	glBegin(GL_QUADS);
	glColor3f(rgb[0], rgb[1], rgb[2]);
	glVertex3f(a[0], a[1], a[2]);
	glVertex3f(b[0], b[1], b[2]);
	glVertex3f(c[0], c[1], c[2]);
	glVertex3f(d[0], d[1], d[2]);
	glEnd();
}

void Primitives::drawSnowMan()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	// Draw Body
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);
	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);
	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}


Primitives::~Primitives()
{
}
