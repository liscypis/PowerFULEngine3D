#include "UserInput.h"



UserInput::UserInput()
{
	
}

void UserInput::enableKeyboard() {
	glutKeyboardFunc(keyboardFunction);
}

void UserInput::enableMouse() {
	glutMouseFunc(mouseFunction);
}

void UserInput::keyboardFunction(unsigned char c, int x, int y) {

}

void UserInput::mouseFunction(int button, int state, int x, int y) {

}

UserInput::~UserInput()
{
}
