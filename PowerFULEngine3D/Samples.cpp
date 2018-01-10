#include "Samples.h"
#include "Primitives.h"
#include "Camera.h"
#include "UserInput.h"
#include "Engine.h"
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

	glClearColor(0.05f, 0.35f, 0.7f, 1.0f);
	//Engine::AmbientLighting();
	//Engine::PointLight(0.0f, 0.0f, 1.5f, 0, 1, 1);
	Engine::PointLight(0.0f, 0.0f, -10.5f, 0, 1, 1);
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
		glTranslatef(-5.0f, 0.0f, 0.0f); // Translate 5 Units Right
		glutSolidTeapot(2.0f);
	glPopMatrix();
}


Samples::~Samples()
{
}


