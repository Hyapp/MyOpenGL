#include"OpenGL.h"

namespace MyOpenGL
{
	_CreateWindow::_CreateWindow(int width, int height, const GLchar * title, GLFWmonitor * monitor, GLFWwindow * share)
	{
		window = glfwCreateWindow(width, height, title, monitor, share);
	}

	_CreateWindow::_CreateWindow(int width, int height, const std::string title, GLFWmonitor * monitor, GLFWwindow * share)
	{
		window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
	}

	_CreateWindow::_CreateWindow(_CreateWindow & window0)
	{
		this->window = window0.window;
		window0.window = nullptr;
	}

	_CreateWindow & _CreateWindow::operator=(const _CreateWindow & rhs)
	{
		this->window = rhs.window;
		rhs.window = nullptr;
		return *this;
	}

	_CreateWindow::~_CreateWindow(void)
	{
		this->window = nullptr;
	}

	GLFWwindow * _CreateWindow::use()
	{
		return (!window) ? nullptr : window;
	}
	bool _CreateWindow::available(void)
	{
		return (window) ? true : false;
	}
}