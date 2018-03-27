#include"OpenGL.h"

namespace MyOpenGL
{
	_GLADInitialization::_GLADInitialization(void)
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			this->boolean = false;
		}
		else
		{
			this->boolean = true;
		}
	}

	void _GLADInitialization::ReInitialization(void)
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			this->boolean = false;
		}
		else
		{
			this->boolean = true;
		}
	}

	bool _GLADInitialization::Available(void)
	{
		return boolean;
	}
}