#include "window.h"

namespace sparky { namespace graphics {
	 
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

	void Window::update() const
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
	
	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to init GLFW " << std::endl;
			return false; 
		}
		system("PAUSE");
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}


} }