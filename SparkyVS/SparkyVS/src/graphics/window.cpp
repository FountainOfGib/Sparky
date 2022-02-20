#include "window.h"

namespace sparky { namespace graphics {
	
	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(const char* name, int width, int height)
	{
		m_Name = name;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to init GLFW " << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW is the big SAD" << std::endl;
			return false;
		}
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void Window::update()
	{
		glfwSwapBuffers(m_Window);
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glViewport(0, 0, m_Width, m_Height);
		glfwPollEvents();
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	inline int Window::getWidth() const { return m_Width; }
	inline int Window::getHeight() const { return m_Height; }

} }