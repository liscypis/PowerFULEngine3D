#include "Engine.h"
#include "Window.h"
#include "Primitives.h"
#include <xutility>


void Engine::engineInit()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(this->mode);
	glutInitWindowPosition(this->vpos, this->hpos);
	glutInitWindowSize(this->screen_w, this->screen_h);
}


void Engine::display(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Primitives::triangle();
	glutSwapBuffers();
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
	glutDisplayFunc(display);
	glutReshapeFunc(Window::resize);
	glutMainLoop();
}


Engine::~Engine() 
{
	Window::destroyWindow(this->create);
}


void Engine::running()
{

}
