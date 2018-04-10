#include"OpenGL.h"

namespace MyOpenGL
{
	template<typename T>
	inline _Color<T>::_Color(T & red, T & green, T & blue, T & a)
	{
		this->red = static_cast<float>(red);
		this->green = static_cast<float>(green);
		this->blue = static_cast<float>(blue);
		this->a = static_cast<float>(a);
	}

	template<typename T>
	_Color<T>::_Color(void)
	{
		this->red = 0.0f;
		this->green = 0.0f;
		this->blue = 0.0f;
		this->a = 0.0f;
	}

	template<typename T>
	MyOpenGL::_Color<T>::_Color(_Color<T>& color)
	{
		this->red = color.red;
		this->green = color.green;
		this->blue = color.blue;
		this->a = color.a;
	}

	template<typename T>
	MyOpenGL::_Color<T>::_Color(T && red, T && green, T && blue, T && a)
	{
		this->red = static_cast<float>(red);
		this->green = static_cast<float>(green);
		this->blue = static_cast<float>(blue);
		this->a = static_cast<float>(a);
	}

	template<typename T>
	bool _Color<T>::SetColor(T & red, T & green, T & blue, T & a)
	{
		try
		{
			this->red = static_cast<float>(red);
			this->green = static_cast<float>(green);
			this->blue = static_cast<float>(blue);
			this->a = static_cast<float>(a);
			return true;
		}
		catch (const std::exception&)
		{
			return false
		}
		return false;
	}

	template<typename T>
	template<typename T1>
	_Color<T> _Color<T>::operator=(const _Color<T1>& rhs)
	{
		this->red = rhs.red;
		this->green = rhs.green;
		this->blue = rhs.blue;
		this->a = rhs.a;
		return *this;
	}

	template<typename T>
	template<typename T1>
	bool _Color<T>::operator==(const _Color<T1>& rhs) const
	{
		if (
			rhs.red != this->red &&
			rhs.green != this->green &&
			rhs.blue != this->blue &&
			rhs.a != this->a
			)
		{
			return false;
		}
		else
		{
			return true;
		}
		return false;
	}
}