#include"OpenGL.h"

namespace MyOpenGL
{
	template<typename T>
	_Background::_Background(const T& color)
	{
		try
		{
			this->color.red = color.red;
			this->color.green = color.green;
			this->color.blue = color.blue;
			this->color.a = color.a;
			this->stuta = true;
		}
		catch (const std::exception&)
		{
			this->color = _Color<float>(0.0f, 0.0f, 0.0f, 0.0f);
			this->stuta = false;
		}
	}

	bool _Background::SetBackground(const GLfloat red, const GLfloat green, const GLfloat blue, const GLfloat a)
	{
		try
		{
			this->color.red = red;
			this->color.green = green;
			this->color.blue = blue;
			this->color.a = a;
			this->stuta = true;
			return true;
		}
		catch (const std::exception&)
		{
			this->stuta = false;
			return false;
		}
	}

	template<typename T>
	bool _Background::SetBackground(const _Color<T>& color)
	{
		try
		{
			this->color = color;
			this->stuta = true;
			return true;
		}
		catch (const std::exception&)
		{
			this->stuta = false;
			return false;
		}
	}

	void _Background::Use(void)
	{
		if (this->stuta)
		{
			glClearColor(color.red, color.green, color.blue, color.a);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	}
}