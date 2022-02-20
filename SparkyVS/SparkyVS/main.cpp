#include <iostream>

#include "src/graphics/window.h"

int main() 
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.update();

	}

	return 0;
}