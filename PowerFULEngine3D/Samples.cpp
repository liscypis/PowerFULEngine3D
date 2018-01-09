#include "Samples.h"
#include "Primitives.h"
#include "Camera.h"
#include "UserInput.h"
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
void Samples::drawSampleObjects() {
	glLoadIdentity();
	enableUserInputs();
	Primitives p;
		p.terrain(
		{ -100.0f, 0.0f, -100.0f },
		{ -100.0f, 0.0f, 100.0f },
		{ 100.0f, 0.0f, 100.0f },
		{ 100.0f, 0.0f, -100.0f },
		{ 0.15f,0.7f,0.4f });
	// Draw 36 SnowMen
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j * 10.0);
			p.drawSnowMan();
			glPopMatrix();
		}
	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f); // Translate 5 Units Left
	p.triangle({ 10.0f,0.0f,10.0f }, { 10.0f,0.0f,-10.0f }, { 10.0f, 5.0f, 4.0f }, { 0.55f,0.0f,0.0f });
	glPopMatrix();
}


Samples::~Samples()
{
}


