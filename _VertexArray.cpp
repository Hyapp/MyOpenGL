#include"OpenGL.h"

namespace MyOpenGL
{
	_VertexArray::_VertexArray(void)
	{
		glGenVertexArrays(1, &(this->VAO));
		glBindVertexArray(this->VAO);
	}

	_VertexArray::~_VertexArray(void)
	{
		glDeleteVertexArrays(1, &(this->VAO));
	}
	void _VertexArray::ReBind(void)
	{
		glBindVertexArray(this->VAO);
	}
}