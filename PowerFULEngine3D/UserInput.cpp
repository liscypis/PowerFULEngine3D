#include "UserInput.h"
#include "Engine.h"
#include "Camera.h"


UserInput::UserInput()
{
	
}


void UserInput::enableKeyboard()
{
	glutKeyboardFunc(keyboardFunction);
	glutSpecialFunc(processSpecialKeys);
}
void UserInput::enableMouse() 
{
	glutMouseFunc(mouseFunction);
}

void UserInput::keyboardFunction(unsigned char c, int x, int y) 
{
	Engine::close(c);
	Camera::changeSpeed(c);
}


void UserInput::processSpecialKeys(int key, int x, int y)
{
	Camera c;
	c.moveCamera(key, x, y);
}
void UserInput::mouseFunction(int button, int state, int x, int y)
{
	Camera c;
	c.moveCamera(button, state, x, y);
}


UserInput::~UserInput()
{
}
