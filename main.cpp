#include"Boost.h"
#include"OpenGL.h"

int main()
{
	using namespace MyOpenGL;
	using namespace Beyond;
	GLFWInitialization::GLFWInit(4, 6);
	_CreateWindow window(800, 800, "Text");
	glfwMakeContextCurrent(window.use());
	_GLADInitialization glad;
	if (!glad.Available() && !window.available())
	{
		return -1;
	}

	Shader shader("Shader\\ma.vs", "Shader\\ma.fs");
	float vertices[] =
	{
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
	};
	unsigned int indices[] =
	{
		0,1,3,
		1,2,3
	};

	_VertexArray vertexarray;
	_ArrayBuffer arraybuffer(sizeof(vertices), vertices, _GL_PLOT_WAY::static_draw);
	_VertexAttrubPoint(0, 3, 8, (void *)0);
	_VertexAttrubPoint(1, 3, 8, (void *)(3 * sizeof(float)));
	_VertexAttrubPoint(2, 2, 8, (void *)(6 * sizeof(float)));

	_Texture2D texture("timg.jpg");
	_VertexElement elementbuffer(sizeof(indices), indices, sizeof(vertices), vertices, _GL_PLOT_WAY::static_draw);

	__Background background(__Color(0.0f, 0.0f, 0.0f, 1.0f));
	while (!glfwWindowShouldClose(window.use()))
	{
		background.Use();
		texture.ReBind();
		shader.use();
		vertexarray.ReBind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window.use());
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}