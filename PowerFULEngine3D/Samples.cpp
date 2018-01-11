#include "Samples.h"
#include "Primitives.h"
#include "Camera.h"
#include "UserInput.h"
#include "Light.h"
#include "Window.h"
#include "Number.h"
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

	Camera c;
		c.enableCamera();

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

	
	glPushMatrix();
		glTranslatef(4.0f, 2.0f, 0.0f);
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
		glTranslatef(-5.0f, 2.0f, 0.0f); 
		glutSolidTeapot(2.0f);
	glPopMatrix();

	Text t;
	Number n(Window::getWidth());
	Number n2(Window::getHeight());

	t.renderSpacedBitmapString(5, 30, 1,"Resolution" );
	t.renderSpacedBitmapString(150,30,1, n.toChar());
	t.renderSpacedBitmapString(200, 30, 1, "x");
	t.renderSpacedBitmapString(210, 30, 1, n2.toChar());

	Number n3(c.getSpeed());

	t.renderSpacedBitmapString(5, 60, 1, "(C)amera speed: ");
	t.renderSpacedBitmapString(190, 60, 1, n3.toChar());
	t.renderSpacedBitmapString(200, 60, 1, "X");
}


Samples::~Samples()
{
}


