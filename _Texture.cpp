#include"OpenGL.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

namespace MyOpenGL
{
	_Texture2D::_Texture2D(const std::string & file)
	{
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		auto imagedata = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if (imagedata)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imagedata);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load the picture!" << std::endl;
		}
		stbi_image_free(imagedata);
	}
	void _Texture2D::ReBind()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}