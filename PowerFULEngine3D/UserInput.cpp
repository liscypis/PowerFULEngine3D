#include "UserInput.h"
#include "Engine.h"



UserInput::UserInput()
{
	
}

void UserInput::enableKeyboard() {
	glutKeyboardFunc(keyboardFunction);
	glutSpecialFunc(processSpecialKeys);
}

void UserInput::enableMouse() {
	glutMouseFunc(mouseFunction);
}

void UserInput::keyboardFunction(unsigned char c, int x, int y) {
	
	if (c==27)
	{
		exit(0);
	}

}


void UserInput::processSpecialKeys(int key, int x, int y) {
	Engine::keyboardEngineFunction(key,x,y);
}
void UserInput::mouseFunction(int button, int state, int x, int y) {

}

UserInput::~UserInput()
{
}
