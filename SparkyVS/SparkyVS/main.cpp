#include <iostream>

#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main() 
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	vec2 v2a(1.0f, 2.0f);
	vec2 v2b(3.0f, 4.0f);

	vec3 v3a(1.0f, 2.0f, 3.0f);
	vec3 v3b(3.0f, 4.0f, 5.0f);

	vec4 v4a(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 v4b(3.0f, 4.0f, 5.0f, 6.0f);


	while (!window.closed())
	{
		std::cout << v2a << std::endl;
		v2a += v2b;
		std::cout << v2a << std::endl;


		std::cout << v3a << std::endl;
		v3a += v3b;
		std::cout << v3a << std::endl;


		std::cout << v4a << std::endl;
		v4a += v4b;
		std::cout << v4a << std::endl;

		window.clear();
		//double x, y;
		//window.getMousePosition(x, y);
		//std::cout << x << "    " << y << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif


		window.update();

	}

	return 0;
}