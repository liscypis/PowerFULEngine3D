#include "Number.h"
#include <string>


Number::Number(int number)
{
	this->number = number;
}

char* Number::toChar()
{
	std::string str = std::to_string(this->number);
	cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}


Number::~Number()
{
}