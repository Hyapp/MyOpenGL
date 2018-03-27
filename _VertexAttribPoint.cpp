#include"OpenGL.h"

namespace MyOpenGL
{
	_VertexAttrubPoint::_VertexAttrubPoint(unsigned int name, unsigned int dataLength, unsigned int allLength, void * point, int type, int boolean)
	{
		glVertexAttribPointer(name, dataLength, type, boolean, allLength * sizeof(GLfloat), point);
		glEnableVertexAttribArray(name);
	}
}