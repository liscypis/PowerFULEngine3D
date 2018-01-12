#include "Light.h"
#include "glut.h"
#include "gl\GLU.h"
#include "gl\GL.h"



Light::Light()
{
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void Light::ambientLight() 
{
	double amb = .9;
	GLfloat global_ambient[] = { amb,amb,amb, 0.1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
}

void Light::pointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
	GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
	GLfloat light_diffuse[] = { diff, diff, diff, 1.0 };
	GLfloat light_specular[] = { spec, spec, spec, 1.0 };
	GLfloat light_position[] = { x,y,z, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHT0); 
}

Light::~Light()
{
}
