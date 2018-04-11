#include"Boost.h"
#include"OpenGL.h"
#include"Graphics.h"
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>

void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	using namespace MyOpenGL;
	using namespace Beyond;
	using namespace MyGraphics;
	GLFWInitialization::GLFWInit(4, 6);
	_CreateWindow window(800, 800, "Text");

	glfwMakeContextCurrent(window.Use());
	glfwSetFramebufferSizeCallback(window.Use(), framebuffer_size_callback);

	_GLADInitialization glad;
	if (!glad.Available() && !window.Available())
	{
		return -1;
	}
	glEnable(GL_DEPTH_TEST);

	Shader shader("Shader\\ma.vs", "Shader\\ma.fs");
	cuda Cudas;
	float *vertices = Cudas.Use();

	_VertexArray vertexarray;
	_ArrayBuffer arraybuffer(36*5, vertices, _GL_PLOT_WAY::static_draw);
	_VertexAttrubPoint(0, 3, 5, (void *)0);
	_VertexAttrubPoint(1, 2, 5, (void *)(3 * sizeof(float)));

	_Texture2D texture("timg.jpg");
	texture.AddTexture("a.png");
	shader.Use();
	shader.SetInt("texture1", 0);
	shader.SetInt("texture2", 1);
	__Background background(__Color(0.0f, 0.0f, 0.0f, 1.0f));
	while (!glfwWindowShouldClose(window.Use()))
	{
		processInput(window.Use());
		background.Use();
		glClear(GL_DEPTH_BUFFER_BIT);
		glm::mat4 model(1.0f);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		glm::mat4 view(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), static_cast<float>(1), 0.1f, 100.0f);
		texture.ReBind();
		shader.SetMatrix4f("model", glm::value_ptr(model));
		shader.SetMatrix4f("view", glm::value_ptr(view));
		shader.SetMatrix4f("projection", glm::value_ptr(projection));
		shader.Use();
		vertexarray.ReBind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glfwSwapBuffers(window.Use());
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}