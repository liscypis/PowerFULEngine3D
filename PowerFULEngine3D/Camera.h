#include <math.h>
#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"
class Camera
{
	static float angle;

	static float lx;
	static float lz;

	static float x;
	static float z;
	static float deltaAngle;
	static float deltaAngleX;
	static float deltaMove;
	static int xOrigin;
public:
	Camera();
	static void computePosition(float deltaMove);
	static void computeDirectory(float deltaAngle);
	void moveCamera(unsigned char key, int x, int y);
	void moveCamera(int button, int state, int x, int y);
	static void stopCamera(int key, int x, int y);
	static void mouseMotion(int x, int y);
	void enableCamera();

	~Camera();
};

