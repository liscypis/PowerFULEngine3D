#include "Samples.h"
#include "Primitives.h"
#include "Camera.h"
#include "UserInput.h"
#include "Light.h"
#include "Text.h"
#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"

Samples::Samples()
{
}

void Samples::enableUserInputs() {
	UserInput ui;
		ui.enableKeyboard();
		ui.enableMouse();
	Camera c;
		c.enableCamera();
}

void Samples::enableLightning() {
	Light l;
	l.ambientLight();
	l.pointLight(25.0f, 12.0f, 13.0, 0.0, 0.8, 0.0);
}

void Samples::drawSampleObjects() {
	glLoadIdentity();
	glClearColor(0.05f, 0.35f, 0.7f, 1.0f);

	Samples::enableUserInputs();
	Samples::enableLightning();

	Primitives p;
		p.terrain(
		{ -100.0f, 0.0f, -100.0f },
		{ -100.0f, 0.0f, 100.0f },
		{ 100.0f, 0.0f, 100.0f },
		{ 100.0f, 0.0f, -100.0f },
		{ 0.15f,0.7f,0.4f });

	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j * 10.0);
			p.drawSnowMan();
			glPopMatrix();
		}
	Text t;
	
	glPushMatrix();
		p.drawSphere(1, 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(5.0f, 0.0f, 0.0f); 
		p.triangle({ 10.0f,0.0f,10.0f }, { 10.0f,0.0f,-10.0f }, { 10.0f, 5.0f, 4.0f }, { 0.55f,0.0f,0.0f });
	glPopMatrix();
	glPushMatrix();
		p.line({ 0.0f,0.0f,0.0f }, { 0.0f,50.0f,0.0f }, { 0.0f,0.2f,1.0f });
	glPopMatrix();
	glPushMatrix();
		p.line({ 0.0f,0.0f,0.0f }, { 50.0f,0.0f,0.0f }, { 1.0f,0.0f,0.2f });
	glPopMatrix();
	glPushMatrix();
		p.line({ 0.0f,0.0f,0.0f }, { 0.0f,0.0f,50.0f }, { 0.0f,1.0f,0.2f });
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5.0f, 0.0f, 0.0f); 
		glutSolidTeapot(2.0f);
	glPopMatrix();

	///////
	///// Œcierwo fonty do samego konca
	/////

	setOrthographicProjection();

	glPushMatrix();
	glLoadIdentity();
	renderSpacedBitmapString(5,30,1,GLUT_BITMAP_HELVETICA_18,"Lighthouse3D");
	glPopMatrix();

	restorePerspectiveProjection();

	//glutSwapBuffers();
}
void Samples::setOrthographicProjection() {
	int h = 720;
	int w = 1280;
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, w, 0, h);

	// invert the y axis, down is positive
	glScalef(1, -1, 1);

	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -h, 0);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}
void Samples::restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}
void Samples::renderSpacedBitmapString(

			float x,
			float y,
			int spacing,
			void *font,
			char *string) {

  char *c;
  int x1=x;

  for (c=string; *c != '\0'; c++) {

	glRasterPos2f(x1,y);
	glutBitmapCharacter(font, *c);
	x1 = x1 + glutBitmapWidth(font,*c) + spacing;
  }
}


Samples::~Samples()
{
}


