#pragma once
#include<glad\glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<GLFW\glfw3.h>
#include<vector>

namespace MyOpenGL
{
	class Shader
	{
	public:
		unsigned int ID;
		Shader(const GLchar * vertexPath, const GLchar * fragmentPath);

		void Use();

		void SetBool(const std::string &name, bool value) const;
		void SetBool(const std::string &name, bool value1, bool value2) const;
		void SetBool(const std::string &name, bool value1, bool value2, bool value3) const;
		void SetBool(const std::string &name, bool value1, bool value2, bool value3, bool value4) const;

		void SetInt(const std::string &name, GLint value) const;
		void SetInt(const std::string &name, GLint value1, GLint value2)const;
		void SetInt(const std::string &name, GLint value1, GLint value2, GLint value3)const;
		void SetInt(const std::string &name, GLint value1, GLint value2, GLint value3, GLint value4)const;

		void SetFloat(const std::string &name, GLfloat value)const;
		void SetFloat(const std::string &name, GLfloat value1, GLfloat value2)const;
		void SetFloat(const std::string &name, GLfloat value1, GLfloat value2, GLfloat value3)const;
		void SetFloat(const std::string &name, GLfloat value1, GLfloat value2, GLfloat value3, GLfloat value4)const;

		void SetMatrix4f(const std::string &name, const GLfloat *value);
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
		GLFWwindow * Use(void) const;
		bool Available(void);
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

	class _VertexElement
	{
	public:
		_VertexElement(unsigned int num, unsigned int* data, unsigned int numArray, GLfloat * arrayData, _GL_PLOT_WAY);
		~_VertexElement(void);
	private:
		unsigned int EBO;
	};

	class _Texture2D
	{
	public:
		_Texture2D(const std::string & file);
		bool AddTexture(const std::string & file);
		void ReBind();
	private:
		std::vector<unsigned int> texture;
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
		_Color<T> operator = (const _Color<T1> & rhs);
		template<typename T1>
		bool operator ==(const _Color<T1> & rhs) const;
		bool SetColor(T &red, T &green, T &blue, T &a);
	private:
		float red, green, blue, a;
	};

	class _Background
	{
	public:
		template<typename T>
		_Background(const T &color);

		bool SetBackground(const GLfloat red, const GLfloat green, const GLfloat blue, const GLfloat a);

		template<typename T>
		bool SetBackground(const _Color<T> &color);

		void Use(void);
	private:
		_Color<GLfloat> color;
		bool stuta;
	};
}