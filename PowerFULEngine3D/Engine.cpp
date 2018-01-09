
#include "Engine.h"
#include "Window.h"
#include "UserInput.h"



float Engine::angle = 0.0f;


// actual vector representing the camera's direction
float Engine::lx=0.0f;
float Engine::lz=-1.0f;
// XZ position of the camera
float Engine::x=0.0f;
float Engine::z=5.0f;

void Engine::engineInit()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(this->mode);
	glutInitWindowPosition(this->vpos, this->hpos);
	glutInitWindowSize(this->screen_w, this->screen_h);
}

void Engine::drawSnowMan()
{
	//Color
	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glutSolidCone(0.08f,0.5f,10,2);

}

void Engine::renderScene(void) {
	gluPerspective(60,16/9,1,1000);
 
	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

        // Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

        // Draw 36 SnowMen
	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			Engine::drawSnowMan();
			glPopMatrix();
		}

	glutSwapBuffers();
}


void Engine::display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Primitives::triangle();
	glutSwapBuffers();
}

void Engine::keyboardEngineFunction(unsigned char c, int x, int y)
{

float fraction = 0.1f;

	switch (c) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
		lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}

}
Engine::Engine(int width, int height, int vpos, int hpos, char* name, int argc, char **argv) 
{
	this->screen_w = width;
	this->screen_h = height;
	this->mode = GLUT_SINGLE | GLUT_DOUBLE | GLUT_RGBA;
	this->name = name;
	this->argc = argc;
	this->argv = argv;
	this->vpos = vpos;
	this->hpos = hpos;
	engineInit();
	this->create = Window::createWindow(name);
	glutDisplayFunc(renderScene);
	glutReshapeFunc(Window::resize);
	glutIdleFunc(renderScene);
	UserInput ui;
	ui.enableKeyboard();
	ui.enableMouse();
	glutMainLoop();
}


Engine::~Engine() 
{
	Window::destroyWindow(this->create);
}


void Engine::running()
{

}
