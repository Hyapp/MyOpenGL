#include"OpenGL.h"

namespace MyOpenGL
{
	_VertexElement::_VertexElement(unsigned int num, unsigned int * data, unsigned int numArray, GLfloat * arrayData, _GL_PLOT_WAY way)
	{
		glGenBuffers(1, &EBO);
		switch (way)
		{
		case _GL_PLOT_WAY::static_draw:
			glBufferData(GL_ARRAY_BUFFER, numArray * sizeof(arrayData[0]), arrayData, GL_STATIC_DRAW);
			break;
		case _GL_PLOT_WAY::dynamic_draw:
			glBufferData(GL_ARRAY_BUFFER, numArray * sizeof(arrayData[0]), arrayData, GL_DYNAMIC_DRAW);
			break;
		default:
		{
			std::cout << "There is no way to draw! Default useing the Static_DRAW!" << std::endl;
			glBufferData(GL_ARRAY_BUFFER, numArray * sizeof(arrayData[0]), arrayData, GL_STATIC_DRAW);
		}
		break;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		switch (way)
		{
		case _GL_PLOT_WAY::static_draw:
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_STATIC_DRAW);
			break;
		case _GL_PLOT_WAY::dynamic_draw:
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_DYNAMIC_DRAW);
			break;
		default:
		{
			std::cout << "There is no way to draw! Default useing the Static_DRAW!" << std::endl;
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, num * sizeof(data[0]), data, GL_STATIC_DRAW);
		}
		break;
		}
	}

	_VertexElement::~_VertexElement()
	{
		glDeleteBuffers(1, &EBO);
	}
}