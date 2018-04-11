#include"OpenGL.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

namespace MyOpenGL
{
	_Texture2D::_Texture2D(const std::string & file)
	{
		texture.push_back(0);
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		auto imagedata = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);

		glGenTextures(1, &(texture[0]));
		glBindTexture(GL_TEXTURE_2D, texture[0]);

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
			if (this->texture.size())
			{
				this->texture.pop_back();
			}
		}
		stbi_image_free(imagedata);
	}

	bool _Texture2D::AddTexture(const std::string & file)
	{
		this->texture.push_back(0);
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		auto data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
		

		glGenTextures(1, &(texture[texture.size() - 1]));
		glBindTexture(GL_TEXTURE_2D, texture[texture.size() - 1]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			stbi_image_free(data);
			return true;
		}
		else
		{
			std::cout << "Failed to load the picture!" << std::endl;
			if (this->texture.size())
			{
				texture.pop_back();
			}
			stbi_image_free(data);
			return false;
		}
	}

	void _Texture2D::ReBind()
	{
		for (size_t i = 0; i < texture.size(); ++i)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, texture[i]);
		}
	}
}