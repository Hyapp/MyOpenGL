#include"OpenGL.h"

namespace MyOpenGL
{
	template<typename T>
	inline _Background::_Background(_Color<T> &color)
	{
		this->color.red = color.red;
		this->color.green = color.green;
		this->color.blue = color.blue;
		this->color.a = color.a;
	}

	bool _Background::SetBackground(GLfloat red, GLfloat green, GLfloat blue, GLfloat a)
	{
		try
		{
			this->color.red = red;
			this->color.green = green;
			this->color.blue = blue;
			this->color.a = a;
			return true;
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	template<typename T>
	bool _Background::SetBackground(_Color<T>& color)
	{
		try
		{
			this->color = color;
			return true
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	void _Background::Use(void)
	{
		glClearColor(color.red, color.green, color.blue, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}