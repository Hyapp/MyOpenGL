#include"OpenGL.h"


namespace MyOpenGL
{
	Shader::Shader(const GLchar * vertexPath, const GLchar * fragmentPath)
	{
		std::string vertexCode, fragmentCode;
		std::ifstream vShaderFile, fShaderFile;
		//expection
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			vShaderFile.close();
			fShaderFile.close();
			//Convent
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		int success;
		char infoLog[1024];

		//Vertex Shader
		auto vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::Shader::Vertex::Compilation failed!" << std::endl;
		}

		auto fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::Shader::Fragment::Compilation failed!" << std::endl;
		}
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 1024, NULL, infoLog);
			std::cout << "ERROR::Shader::Porgram::Linking_Failed!\n" << std::endl;
		}

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	Shader::Shader(const std::string vertexPath, const std::string fragmentPath)
	{
		Shader::Shader(vertexPath.c_str(), fragmentPath.c_str());
	}

	void Shader::Use()
	{
		glUseProgram(ID);
	}

	void Shader::SetBool(const std::string & name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

	void Shader::SetBool(const std::string & name, bool value1, bool value2) const
	{
		glUniform2i(glGetUniformLocation(ID, name.c_str()), value1, value2);
	}

	void Shader::SetBool(const std::string & name, bool value1, bool value2, bool value3) const
	{
		glUniform3i(glGetUniformLocation(ID, name.c_str()), value1, value2, value3);
	}

	void Shader::SetBool(const std::string & name, bool value1, bool value2, bool value3, bool value4) const
	{
		glUniform4i(glGetUniformLocation(ID, name.c_str()), value1, value2, value3, value4);
	}

	void Shader::SetInt(const std::string & name, GLint value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void Shader::SetInt(const std::string & name, GLint value1, GLint value2) const
	{
		glUniform2i(glGetUniformLocation(ID, name.c_str()), value1, value2);
	}

	void Shader::SetInt(const std::string & name, GLint value1, GLint value2, GLint value3) const
	{
		glUniform3i(glGetUniformLocation(ID, name.c_str()), value1, value2, value3);
	}

	void Shader::SetInt(const std::string & name, GLint value1, GLint value2, GLint value3, GLint value4) const
	{
		glUniform4i(glGetUniformLocation(ID, name.c_str()), value1, value2, value3, value4);
	}

	void Shader::SetFloat(const std::string & name, GLfloat value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string & name, GLfloat value1, GLfloat value2) const
	{
		glUniform2f(glGetUniformLocation(ID, name.c_str()), value1, value2);
	}

	void Shader::SetFloat(const std::string & name, GLfloat value1, GLfloat value2, GLfloat value3) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), value1, value2, value3);
	}

	void Shader::SetFloat(const std::string & name, GLfloat value1, GLfloat value2, GLfloat value3, GLfloat value4) const
	{
		glUniform4f(glGetUniformLocation(ID, name.c_str()), value1, value2, value3, value4);
	}

	void Shader::SetVec3(const std::string & name, const glm::vec3 &value) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
	}

	void Shader::SetMatrix4f(const std::string & name,const GLfloat * value)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value);
	}

	void Shader::SetMatrix4f(const std::string & name, const glm::mat4 & value)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}
}