#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"
class Window
{	
	static float ratio;
	static int width, height;
public:
	Window();
	static void resize(int w, int h);
	static int createWindow(char *name);
	static void destroyWindow(int win);
	static int getWidth();
	static int getHeight();
	~Window();
};

