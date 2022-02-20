#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sparky { namespace graphics {

#define MAX_KEYS     1024
#define MAX_BUTTONS  32

	class Window
	{

	private:
		friend struct GLFWwindow;

		const char *m_Name;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		double m_MouseX, m_MouseY;


	public:
		Window(const char* name, int width, int height);
		~Window();
		void update();
		bool closed() const;
		void clear() const;

		int getWidth() const;
		int getHeight() const;

		bool isKeyPressed(unsigned int keycode) const;
		bool isMouseButtonPressed(unsigned int mouseButton) const;
		void getMousePosition(double &x, double &y) const;

	private:
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		bool init();

	};

} }