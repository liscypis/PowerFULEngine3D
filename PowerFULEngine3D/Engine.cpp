#include "Engine.h"
#include <xutility>


void Engine::engineInit()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(this->screen_w, this->screen_h);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple Window");
	glutDisplayFunc(Engine::display);
	glutMainLoop();
}

void Engine::display(void) {
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glColor3f(1, 0, 0);
	glutSolidTeapot(60);
	// Flush buffers to screen

	glFlush();
}


Engine::Engine(int width, int height, char* name, int argc, char **argv) {
	this->screen_w = width;
	this->screen_h = height;
	this->mode = GLUT_RGB;
	this->name = name;
	this->argc = argc;
	this->argv = argv;
}


Engine::~Engine() {

}




void Engine::running()
{
	
}
