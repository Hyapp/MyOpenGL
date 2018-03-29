#pragma once
#include<glad\glad.h>
#include<GLFW\glfw3.h>

namespace Beyond
{
	class __Color
	{
		friend class __Background;
	public:
		__Color(void);
		__Color(float red, float green, float blue, float alpha = 1.0f);
		bool SetRed(const float red);
		bool SetGreen(const float green);
		bool SetBlue(const float blue);
		bool SetAlpha(const float alpha);
		bool Set(const float red, const float green, const float blue, const float alpha);
	private:
		float red, green, blue, alpha;
	};
	class __Background
	{
	public:
		__Background(void);
		__Background(const __Color && color);
		__Background(float && red, float && green, float && blue, float alpha);

		bool Set(const __Color & color);
		bool Set(float && red, float && green, float && blue, float && alpha);
		void Use(void);
	private:
		__Color color;
	};
}