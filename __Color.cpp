#include"Boost.h"

namespace Beyond
{
	__Color::__Color()
	{
		this->red = 0.0f;
		this->green = 0.0f;
		this->blue = 0.0f;		
		this->alpha = 1.0f;
	}

	__Color::__Color(float red, float green, float blue, float alpha) :red(red), green(green), blue(blue)
	{
		this->alpha = alpha;
	}

	bool __Color::SetRed(const float red)
	{
		this->red = red;
		return true;
	}

	bool __Color::SetGreen(const float green)
	{
		this->green = green;
		return true;
	}

	bool __Color::SetBlue(const float blue)
	{
		this->blue = blue;
		return false;
	}

	bool __Color::SetAlpha(const float alpha)
	{
		this->alpha = alpha;
		return true;
	}

	bool __Color::Set(const float red, const float green, const float blue, const float alpha)
	{
		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
		return true;
	}


}