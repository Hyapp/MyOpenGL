#include"OpenGL.h"

namespace MyOpenGL
{
	_VertexReference::_VertexReference(void)
	{
		glGenVertexArrays(1, &(this->VAO));
	}

	_VertexReference::~_VertexReference(void)
	{
		glDeleteVertexArrays(1, &(this->VAO));
	}
	void _VertexReference::ReBind(void)
	{
		glBindVertexArray(this->VAO);
	}
}