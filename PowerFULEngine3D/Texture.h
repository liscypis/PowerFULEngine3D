#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"
class Texture
{
	int loadImage(const char * theFileName);
public:
	Texture();
	static GLuint textureRepository[12];
	void insertTextures();
	~Texture();
};

