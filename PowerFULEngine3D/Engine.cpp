#include "Engine.h"
#include <xutility>


void Engine::engineInit(int vpos, int hpos)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(this->screen_w, this->screen_h);
	glutInitWindowPosition(vpos, hpos);
}

int Engine::createWindow(char *name)
{
	return glutCreateWindow(name);
}

void Engine::destroyWindow(int win)
{
	glutDestroyWindow(win);
}

void Engine::display(void) {

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -4.5);
	// Red color used to draw.
	glColor3f(0.8, 0.2, 0.1);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(30.0, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(30.0, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(30.0, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a Teapot.
	glutSolidTeapot((GLdouble)1.0);
	// Flush buffers to.0 screen

	glFlush();
	// sawp buffers called because we are using double buffering 
	 //glutSwapBuffers();
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0

	gluPerspective(40.0, (GLdouble)20 / (GLdouble)20, 0.5, 20.0);

	glViewport(0, 0, 20, 20);  //Use the whole window for rendering


}


Engine::Engine(int width, int height, int vpos, int hpos, char* name, int argc, char **argv) {
	this->screen_w = width;
	this->screen_h = height;
	this->mode = GLUT_SINGLE|GLUT_RGB;
	this->name = name;
	this->argc = argc;
	this->argv = argv;
	engineInit(vpos, hpos);
	int create = createWindow(name);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Engine::display);
	glutMainLoop();
	destroyWindow(create);
}


Engine::~Engine() {

}


void Engine::running()
{

}
