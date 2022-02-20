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

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update()
	{
		glfwSwapBuffers(m_Window);
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

	inline int Window::getWidth() const { return m_Width; }
	inline int Window::getHeight() const { return m_Height; }

	void windowResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = (bool)(action != GLFW_RELEASE);
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = (bool)(action != GLFW_RELEASE);
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseX = xpos;
		win->m_MouseY = ypos;
	}

	bool Window::isKeyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;
		return m_Keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int mouseButton)const
	{
		if (mouseButton >= MAX_BUTTONS)
			return false;
		return m_MouseButtons[mouseButton];
	}

	void Window::getMousePosition(double& x, double& y) const
	{
		x = m_MouseX;
		y = m_MouseY;
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
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW is the big SAD" << std::endl;
			return false;
		}
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		return true;
	}
} }