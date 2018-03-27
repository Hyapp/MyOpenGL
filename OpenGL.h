#pragma once
#include<glad\glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<GLFW\glfw3.h>

namespace MyOpenGL
{
	class Shader
	{
	public:
		unsigned int ID;
		Shader(const GLchar * vertexPath, const GLchar * fragmentPath);

		void use();

		void setBool(const std::string &name, bool value) const;
		void setBool(const std::string &name, bool value1, bool value2) const;
		void setBool(const std::string &name, bool value1, bool value2, bool value3) const;
		void setBool(const std::string &name, bool value1, bool value2, bool value3, bool value4) const;

		void setInt(const std::string &name, GLint value) const;
		void setInt(const std::string &name, GLint value1, GLint value2)const;
		void setInt(const std::string &name, GLint value1, GLint value2, GLint value3)const;
		void setInt(const std::string &name, GLint value1, GLint value2, GLint value3, GLint value4)const;

		void setFloat(const std::string &name, GLfloat value)const;
		void setFloat(const std::string &name, GLfloat value1, GLfloat value2)const;
		void setFloat(const std::string &name, GLfloat value1, GLfloat value2, GLfloat value3)const;
		void setFloat(const std::string &name, GLfloat value1, GLfloat value2, GLfloat value3, GLfloat value4)const;
	};

	class GLFWInitialization
	{
	public:
		static void GLFWInit(int major_version,int minor_version);
	};

	class _CreateWindow
	{
	public:
		explicit _CreateWindow(int width, int height, const GLchar * title, GLFWmonitor * monitor = NULL, GLFWwindow * share = NULL);
		explicit _CreateWindow(int width, int height, const std::string title, GLFWmonitor * monitor = NULL, GLFWwindow * share = NULL);
		_CreateWindow(_CreateWindow & window0);
		_CreateWindow & operator =(const _CreateWindow &rhs);
		~_CreateWindow(void);
		GLFWwindow* use(void);
		bool available(void);
	private:
		mutable GLFWwindow * window = nullptr;
	};

	class _GLADInitialization
	{
	public:
		_GLADInitialization(void);
		void ReInitialization(void);
		bool Available();
	private:
		bool boolean;
	};

	class _VertexArray
	{
	public:
		explicit _VertexArray(void);
		~_VertexArray(void);
		void ReBind(void);
	private:
		unsigned int VAO;
	};

	enum class _GL_PLOT_WAY
	{
		static_draw,
		dynamic_draw
	};

	class _ArrayBuffer
	{
	public:
		explicit _ArrayBuffer(unsigned int num, GLfloat * data, _GL_PLOT_WAY);
		~_ArrayBuffer(void);
	private:
		unsigned int VBO;
	};

	class _VertexAttrubPoint
	{
	public:
		_VertexAttrubPoint(unsigned int name, unsigned int dataLength, unsigned int allLength, void * point, int type = GL_FLOAT, int boolean = GL_FALSE);
	};

	template<typename T>
	class _Color
	{
		friend class _Background;
	public:
		_Color(void);
		_Color(T &red, T &green, T &blue, T &a);
		_Color(T &&red, T &&green, T &&blue, T &&a);
		_Color(_Color<T> & color);
		template<typename T1>
		_Color<T> operator = (const _Color<T1> & lastColor);
		bool SetColor(T &red, T &green, T &blue, T &a);
	private:
		GLfloat red, green, blue, a;
	};

	class _Background
	{
	public:
		template<typename T>
		_Background(_Color<T> &color);
		bool SetBackground(GLfloat red, GLfloat green, GLfloat blue, GLfloat a);
		template<typename T>
		bool SetBackground(_Color<T> &color);

		void Use(void);
	private:
		_Color<GLfloat> color;
	};
}