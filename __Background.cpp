#include"Boost.h"

namespace Beyond
{
	__Background::__Background(void)
	{
		this->color.Set(0.0f, 0.0f, 0.0f, 1.0f);
	}
	__Background::__Background(const __Color && color)
	{
		this->color = color;
	}

	__Background::__Background(float && red, float && green, float && blue, float alpha)
	{
		this->color = __Color(red, green, blue, alpha);
	}

	bool __Background::Set(const __Color & color)
	{
		this->color = color;
		return true;
	}

	bool __Background::Set(float && red, float && green, float && blue, float && alpha)
	{
		this->color = __Color(red, green, blue, alpha);
		return false;
	}

	void __Background::Use(void)
	{
		glClearColor(color.red, color.green, color.blue, color.alpha);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}