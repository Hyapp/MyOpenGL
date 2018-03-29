#include"OpenGL.h"
#include"Boost.h"
#include<memory>

int main(int argc, char *argv[])
{
	std::unique_ptr<float[]> GetMandelbortPoints();
	using namespace MyOpenGL;
	using namespace Beyond;
	
	GLFWInitialization::GLFWInit(4, 6);
	_CreateWindow window0(1920, 1080, "Maoxian");
	if (!window0.available())
	{
		return -1;
	}

	glfwMakeContextCurrent(window0.use());
	
	_GLADInitialization glad;
	if (!glad.Available())
	{
		return -1;
	}

	Shader shader("Shader\\ma.vs", "Shader\\ma.fs");
	auto data = GetMandelbortPoints();
	_VertexArray vertexarray;
	_ArrayBuffer arraybuffer(1920 * 1080 * 3, data.get(), _GL_PLOT_WAY::static_draw);
	_VertexAttrubPoint(0, 3, 3, (void *)0);
//	_Color<int> colo;
//	_Background back(colo);
	__Background background(__Color(1.0f, 1.0f, 1.0f));
	while (!glfwWindowShouldClose(window0.use()))
	{
		back.Use();
		shader.use();
		shader.setFloat("time", static_cast<GLfloat>(glfwGetTime()));
		vertexarray.ReBind();
		glPointSize(1);
		glDrawArrays(GL_POINTS, 0, 1920 * 1080);
		glfwSwapBuffers(window0.use());
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

int Julia(double x, double y, int n)
{
	double xx, yy, p = -0.7454, q = 0.1131;
	int i = 0;
	xx = x * x;
	yy = y * y;
	while (i++ < n)
	{
		y = 2 * x*y + q;
		x = xx - yy + p;
		xx = x * x;
		yy = y * y;
		if ((xx + yy) > 4)
		{
			return i;
		}
	}
	return 0;
}

std::unique_ptr<float[]> GetMandelbortPoints()
{
	unsigned int width = 1920, height = 1080;
	std::unique_ptr<float[]> result(new float[width*height * 3]);
	int c, n = 180;
	float scale = 255.0f / n;
	auto min_a = -1.6, max_a = 1.6, min_b = -1.2, max_b = 1.2;
	auto step_a = (max_a - min_a) / width;
	auto step_b = (max_b - min_b) / height;
	auto a = min_a;
	for (size_t i = 0; i < width; ++i)
	{
		auto b = min_b;
		for (size_t j = 0; j < height; ++j)
		{
			//c = 255 - static_cast<int>(scale * Mandelbrot(a, b, n));
			c = static_cast<int>(scale * Julia(a, b, n));
			b += step_b;
			auto address = (i * height + j) * 3;
			result[address] = static_cast<float>(i);
			result[address + 1] = static_cast<float>(j);
			result[address + 2] = static_cast<float>(c);
		}
		a += step_a;
	}
	for (size_t i = 0; i < width * height * 3; i += 3)
	{
		result[i] -= (width / 2);
		result[i] /= (width / 2);
		result[i + 1] -= (height / 2);
		result[i + 1] /= (height / 2);
		result[i + 2] /= 255;
	}
	return result;
}
