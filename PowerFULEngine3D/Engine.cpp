#include "Engine.h"
#include "Window.h"
#include "Samples.h"

void Engine::engineInit()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(this->mode);
	glutInitWindowPosition(this->vpos, this->hpos);
	glutInitWindowSize(this->screen_w, this->screen_h);
}

void Engine::renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	Samples samples;
	samples.drawSampleObjects();

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
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(Window::resize);
	glutIgnoreKeyRepeat(1);
	glutMainLoop();
}

Engine::~Engine() 
{
	Window::destroyWindow(this->create);
}

void Engine::close(unsigned char c) {
	if (c == 27)
		exit(0);
}
