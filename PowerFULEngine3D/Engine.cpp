#include "Engine.h"
#include <xutility>


void Engine::engineInit()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(this->screen_w, this->screen_h);
	glutInitWindowPosition(100, 100);
}

int Engine::createWindow(char *name)
{
	return glutCreateWindow(name);
}

void Engine::glutDestroy(int win)
{
	glutDestroyWindow(win);
}

void Engine::display(void) {
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glColor3f(1, 0, 0);
	glutSolidTeapot(60);
	glFlush();
}


Engine::Engine(int width, int height, char* name, int argc, char **argv) {
	this->screen_w = width;
	this->screen_h = height;
	this->mode = GLUT_RGB;
	this->name = name;
	this->argc = argc;
	this->argv = argv;
	engineInit();
	int create = createWindow(name);
	glutDisplayFunc(Engine::display);
	glutMainLoop();
	glutDestroy(create);
}


Engine::~Engine() {

}


void Engine::running()
{

}
