
#include <math.h>

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
	// angle of rotation for the camera direction
static float angle;
// actual vector representing the camera's direction
static float lx;
static float lz;
// XZ position of the camera
static float x;
static float z;

public:
	Engine(int width, int height, int vpos, int hpos, char* name, int argc, char **argv);
	~Engine();
	static void display(void);
	static void keyboardEngineFunction(unsigned char c, int x, int y);
	static void renderScene();
	void engineInit();
	static void drawSnowMan();
	void running();
};

