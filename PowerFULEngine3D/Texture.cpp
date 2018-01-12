#include "Texture.h"
#include "glut.h"
#include <IL\il.h>
#include <IL\ilu.h>
Texture::Texture()
{
}

GLuint Texture::textureRepository[12];

void Texture::insertTextures() 
{
	glGenTextures(1, &textureRepository[0]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[0]);
	textureRepository[0] = loadImage("sand.jpg");
	glGenTextures(1, &textureRepository[1]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[1]);
	textureRepository[1] = loadImage("grass2.png");
	glGenTextures(1, &textureRepository[2]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[2]);
	textureRepository[2] = loadImage("brick_wall.png");
	glGenTextures(1, &textureRepository[3]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[3]);
	textureRepository[3] = loadImage("bluecloud_up.jpg");
	glGenTextures(1, &textureRepository[4]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[4]);
	textureRepository[4] = loadImage("wood.jpg");
	glGenTextures(1, &textureRepository[5]);
	glBindTexture(GL_TEXTURE_2D, textureRepository[5]);
	textureRepository[5] = loadImage("MedievalBrick.tiff");
}

int Texture::loadImage(const char* theFileName)// devIL loader
{
	ilInit();
	ILuint imageID;				// Create an image ID as a ULuint
	GLuint textureID;			// Create a texture ID as a GLuint
	ILboolean success;			// Create a flag to keep track of success/failure
	ILenum error;				// Create a flag to keep track of the IL error state
	ilGenImages(1, &imageID); 		// Generate the image ID
	ilBindImage(imageID); 			// Bind the image
	success = ilLoadImage(theFileName); 	// Load the image file
											// If we managed to load the image, then we can start to do things with it...
	if (success)
	{
		// If the image is flipped (i.e. upside-down and mirrored, flip it the right way up!)
		ILinfo ImageInfo;
		iluGetImageInfo(&ImageInfo);
		if (ImageInfo.Origin == IL_ORIGIN_UPPER_LEFT)
		{
			iluFlipImage();
		}
		// Convert the image into a suitable format to work with
		// NOTE: If your image contains alpha channel you can replace IL_RGB with IL_RGBA
		success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
		// Quit out if we failed the conversion
		if (!success)
		{
			error = ilGetError();
			//exit(-1);
		}
		// Generate a new texture
		glGenTextures(1, &textureID);
		// Bind the texture to a name
		glBindTexture(GL_TEXTURE_2D, textureID);
		// Set texture clamping method
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		// Set texture interpolation method to use linear interpolation (no MIPMAPS)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		// Specify the texture specification
		glTexImage2D(GL_TEXTURE_2D, 				// Type of texture
			0,				// Pyramid level (for mip-mapping) - 0 is the top level
			ilGetInteger(IL_IMAGE_BPP),	// Image colour depth
			ilGetInteger(IL_IMAGE_WIDTH),	// Image width
			ilGetInteger(IL_IMAGE_HEIGHT),	// Image height
			0,				// Border width in pixels (can either be 1 or 0)
			ilGetInteger(IL_IMAGE_FORMAT),	// Image format (i.e. RGB, RGBA, BGR etc.)
			GL_UNSIGNED_BYTE,		// Image data type
			ilGetData());			// The actual image data itself
	}
	else // If we failed to open the image file in the first place...
	{
		error = ilGetError();
		//exit(-1);
	}
	ilDeleteImages(1, &imageID); // Because we have already copied image data into texture data we can release memory used by image.

	return textureID; // Return the GLuint to the texture so you can use it!
}

Texture::~Texture()
{
}
