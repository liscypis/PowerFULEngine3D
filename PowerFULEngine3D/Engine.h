#ifndef Engine_h
#define Engine_h

#include <Windows.h>

#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"



class Engine {
	int argc;
	char **argv;
	int create;
	int screen_w;
	int vpos;
	int hpos;
	int screen_h;
	char* name;
	unsigned int mode;
public:
	Engine(int width, int height, int vpos, int hpos, char* name, int argc, char **argv);
	~Engine();
	static void display(void);
	void engineInit();
	void running();
};

#endif