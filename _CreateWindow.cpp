#include"OpenGL.h"

namespace MyOpenGL
{
	_CreateWindow::_CreateWindow(int width, int height, const GLchar * title, GLFWmonitor * monitor, GLFWwindow * share) :width(width), height(height)
	{
		window = glfwCreateWindow(width, height, title, monitor, share);
//		void(*temp)(GLFWwindow *, int, int);
//		temp = reinterpret_cast<void (*)(GLFWwindow *,int,int)>(&SizeChanged);
		//glfwSetFramebufferSizeCallback(window, temp);
		
	}

	_CreateWindow::_CreateWindow(int width, int height, const std::string title, GLFWmonitor * monitor, GLFWwindow * share) : width(width), height(height)
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

	GLFWwindow * _CreateWindow::Use() const
	{
		return (!window) ? nullptr : window;
	}

	bool _CreateWindow::Available(void)
	{
		return (window) ? true : false;
	}

	void _CreateWindow::SizeChanged(GLFWwindow * window, int width, int height)
	{
		if (!Available())
		{
			return;
		}
		else
		{
			glViewport(0, 0, width, height);
			this->width = width;
			this->height = height;
		}
	}

	bool _CreateWindow::SetSizeChangeFun(void(*frame)(GLFWwindow *, int, int))
	{
		try
		{
			this->framebufferSize = frame;
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	void _CreateWindow::SetSizeChangeCallback(bool value)
	{
		this->isFrameSizeOpen = value;
		return;
	}

	void _CreateWindow::nothingToDo(GLFWwindow *, int, int) {}
}