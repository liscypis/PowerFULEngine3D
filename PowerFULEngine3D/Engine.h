#ifndef Engine_h
#define Engine_h

#include <Windows.h>

#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"


class Engine {int argc;
	char **argv;
	

	int screen_w;
	int screen_h;
	char* name;
	unsigned int mode;
public:
	Engine(int width, int height, char* name, int argc, char **argv);
	~Engine();
	void glutDestroy(int win);
	static void display();
	void engineInit();
	static int createWindow(char *name);
	void running();
};

#endif