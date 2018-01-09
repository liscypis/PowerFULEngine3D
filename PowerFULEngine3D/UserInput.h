#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"
class UserInput
{
public:

	UserInput();
	void enableKeyboard();
	void enableMouse();
	static void keyboardFunction(unsigned char c, int x, int y);
	static void processSpecialKeys(int key, int x, int y);
	static void mouseFunction(int button, int state, int x, int y);
	~UserInput();
};

