#include "Samples.h"
#include "Primitives.h"
#include "Camera.h"
#include "UserInput.h"
#include "Light.h"
#include "Window.h"
#include "Texture.h"
#include "Number.h"
#include "Text.h"
#include "glut.h"
Samples::Samples()
{
}
float Samples::angle = 0.0f;
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
	glEnable(GL_TEXTURE_2D);
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*25.0, 0, j * 25.0);
			glBindTexture(GL_TEXTURE_2D, Texture::textureRepository[0]);
			p.terrain(
			{ -25.0f, 0.0f, -25.0f },
			{ -25.0f, 0.0f, 25.0f },
			{ 25.0f, 0.0f, 25.0f },
			{ 25.0f, 0.0f, -25.0f },
			{ 1.0f,1.0f,1.0f });
			glPopMatrix();
		}
	glDisable(GL_TEXTURE_2D);
	for (int i = -3; i < 3; i++)
		for (int j = -1; j < 1; j++) {
			glEnable(GL_TEXTURE_2D);
			glPushMatrix();
			glTranslatef(i*17.0f, 1.5f, j*17.0f);
			glBindTexture(GL_TEXTURE_2D, Texture::textureRepository[4]);
			p.solidCube(3);
			glPopMatrix();
		}
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_2D);
	for (int i = -3; i < 3; i++)
		for (int j = -1; j < 1; j++) {
			glEnable(GL_TEXTURE_2D);
			glPushMatrix();
			glTranslatef(-9.5f*i, 4.5f+4.5f*j, -45.0f);
			glBindTexture(GL_TEXTURE_2D, Texture::textureRepository[5]);
			p.wall(1);
			glPopMatrix();
		}
	glDisable(GL_TEXTURE_2D);
	
	Text t;
	Number n(Window::getWidth());
	Number n2(Window::getHeight());

	t.renderSpacedBitmapString(5, 25, 1, "PowerFULEngine3D");

	t.renderSpacedBitmapString(5, 50, 1,"Resolution" );
	t.renderSpacedBitmapString(150,50,1, n.toChar());
	t.renderSpacedBitmapString(200, 50, 1, "x");
	t.renderSpacedBitmapString(210, 50, 1, n2.toChar());

	Number n3(c.getSpeed());
	t.renderSpacedBitmapString(5, 75, 1, "(C)amera speed: ");
	t.renderSpacedBitmapString(190, 75, 1, n3.toChar());
	t.renderSpacedBitmapString(200, 75, 1, "X");

	glPushMatrix();
	glRotated(angle, 5, 10, 5);
	glTranslated(0, 20, 15);
	p.drawSphere(5, 1);
	glPopMatrix();
	angle += 0.5;
	if(angle==360) angle=0;
}


Samples::~Samples()
{
}


