#include "Window.h"

float Window::ratio;
int Window::width;
int Window::height;

Window::Window()
{
}

void Window::resize(int w, int h) {

	width = w;
	height = h;

	if (h == 0)
		h = 1;

	ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}

int Window::createWindow(char *name)
{
	return glutCreateWindow(name);
}

void Window::destroyWindow(int win)
{
	glutDestroyWindow(win);
}

int Window::getWidth() {
	return width;
}
int Window::getHeight() {
	return height;
}

Window::~Window()
{
}
