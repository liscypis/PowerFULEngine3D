#include "Camera.h"

float Camera::angle = 0.0f;
float Camera::lx = 0.0f;
float Camera::lz = -1.0f;
float Camera::ly = 0.05f;
float Camera::x = 0.0f;
float Camera::z = 5.0f;
float Camera::y = 1.0f;
float Camera::deltaAngle = 0.0f;
float Camera::deltaAngleX = 0.0f;
float Camera::deltaMove = 0.0f;
float Camera::deltaMoveVertical = 0.0f;

int Camera::xOrigin = -1;

Camera::Camera()
{
}

void Camera::computePositionVertical(float deltaMoveVertical)
{
	y += deltaMoveVertical * ly * 0.1f;
}

void Camera::computePosition(float deltaMove) 
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void Camera::computeDirectory(float deltaAngle) 
{
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}
void Camera::moveCamera(unsigned char key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
		case GLUT_KEY_PAGE_UP: deltaMoveVertical = 5.0f; break;
		case GLUT_KEY_PAGE_DOWN: deltaMoveVertical = -5.0f; break;
		case GLUT_KEY_UP: deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
	}
}
void Camera::moveCamera(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) {
			angle -= deltaAngleX;
		}
		else {
			xOrigin = x;
		}
	}
}
void Camera::stopCamera(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
		case GLUT_KEY_PAGE_UP:
		case GLUT_KEY_PAGE_DOWN: deltaMoveVertical = 0; break;
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}

void Camera::mouseMotion(int x, int y)
{
	if (xOrigin >= 0) {
		deltaAngleX = (x - xOrigin) * 0.001f;

		lx = sin(angle - deltaAngleX);
		lz = -cos(angle - deltaAngleX);
	}
}

void Camera::enableCamera()
{
	glutSpecialUpFunc(Camera::stopCamera);
	glutMotionFunc(Camera::mouseMotion);
	if (deltaMove)
		computePosition(deltaMove);
	if (deltaMoveVertical)
		computePositionVertical(deltaMoveVertical);
	if (deltaAngle)
		computeDirectory(deltaAngle);
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

Camera::~Camera()
{
}
