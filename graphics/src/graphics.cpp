#include "../include/graphics/graphics.h"

#define GLEW_STATIC
#include"GL\glew.h"

bool bear::graphics::Graphics::init()
{
	glewExperimental = true;
	GLenum result = glewInit();

	if (result != GLEW_OK) {
		if (result == GLEW_ERROR_NO_GL_VERSION) {
			printf("No GL context ( GLEW_ERROR_NO_GL_VERSION )\n");
		}
		return false;
	}
	else {
		return true;
	}
	return true;
}

bool bear::graphics::Graphics::exit()
{
	return true;
}