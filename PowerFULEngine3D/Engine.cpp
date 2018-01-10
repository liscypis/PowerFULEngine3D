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

void Engine::AmbientLighting()
{
	glEnable(GL_LIGHTING);

	double amb = .3;
	GLfloat global_ambient[] = { amb,amb,amb, 0.1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
}


void Engine::PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
	glEnable(GL_LIGHTING);

	/*
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	*/
	GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
	GLfloat light_diffuse[] = { diff, diff, diff, 1.0 };
	GLfloat light_specular[] = { spec, spec, spec, 1.0 };

	GLfloat light_position[] = { x,y,z, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT0); //enable the light after setting the properties

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
