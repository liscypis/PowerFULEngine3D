#include "Engine.h"



int main(int argc, char **argv)
{
	Engine *e = new Engine(640, 480, "PowerFULEngine3D", argc, argv);
	e->engineInit();


	return 0;
}
