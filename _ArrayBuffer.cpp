#include"OpenGL.h"

namespace MyOpenGL
{
	_ArrayBuffer::_ArrayBuffer(unsigned int num, GLfloat * data, _GL_PLOT_WAY way)
	{
		glGenBuffers(1, &(this->VBO));
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

		switch (way)
		{
		case _GL_PLOT_WAY::static_draw:
			glBufferData(GL_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_STATIC_DRAW);
			break;
		case _GL_PLOT_WAY::dynamic_draw:
			glBufferData(GL_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_DYNAMIC_DRAW);
			break;
		default:
		{
			std::cout << "There is no way to draw! Default useing the Static_DRAW!" << std::endl;
			glBufferData(GL_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_STATIC_DRAW);
		}
			break;
		}
	}

	void _ArrayBuffer::ReBind(void)
	{
		glBindBuffer(GL_ARRAY_BUFFER,VBO);
	}

	_ArrayBuffer::~_ArrayBuffer(void)
	{
		glDeleteBuffers(1, &(this->VBO));
	}
}