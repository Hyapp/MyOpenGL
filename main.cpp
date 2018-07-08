#include"Game.h"
#include"All.h"

unsigned int scr_width = 800, scr_height = 800;
MyCamera::_Camera camera;
float lastX, lastY, yaw = -90.0f, pitch = 0.0f;
bool first_mouse = true;

void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	auto yOffset = static_cast<float>(yoffset);
	const auto fov = camera.GetFov();
	if (fov >= 1.0f && fov <= 45.0f)
	{
		camera.SetFov(fov - yOffset);
	}
	if (fov <= 1.0f)
	{
		camera.SetFov(1.0f);
	}
	if (fov >= 45.0f)
	{
		camera.SetFov(45.0f);
	}
}

void mouse_callback(GLFWwindow * window, double xpos, double ypos)
{	

	auto xPos = static_cast<float>(xpos);
	auto yPos = static_cast<float>(ypos);

	if (first_mouse)
	{
		lastX = xPos;
		lastY = yPos;
		first_mouse = false;
	}

	float xoffset = xPos - lastX;
	float yoffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}
	glm::vec3 front;
	front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch))*sin(glm::radians(yaw));
	camera.SetCameraFront(glm::normalize(front));
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	scr_width = width;
	scr_height = height;
	glViewport(0, 0, width, height);
}

int main()
{
//	using namespace MyOpenGL;
//	using namespace MyGraphics;
//	using namespace Beyond;
//
//	GLFWInitialization::GLFWInit(4, 5);
//	_CreateWindow window(1000, 1000, "Design0");
//	if (!window.Use())
//	{
//		std::cout << "Failed to create window!" << std::endl;
//		return -1;
//	}
//	glfwMakeContextCurrent(window.Use());
////	glfwSetInputMode(window.Use(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	_GLADInitialization glad;
//	if (!glad.Available())
//	{
//		std::cout << "Failed to create glad!" << std::endl;
//		return -1;
//	}
//
//	glfwSetFramebufferSizeCallback(window.Use(), framebuffer_size_callback);
//	glfwSetScrollCallback(window.Use(), scroll_callback);
//	glfwSetCursorPosCallback(window.Use(), mouse_callback);
//
//	glEnable(GL_DEPTH_TEST);
	//Shader planetShader("Shader//planet.vs","Shader//planet.fs");
	//Shader asShader("Shader//asteroid.vs", "Shader//asteroid.fs");
	//Game0::Basic_Sense model4("Model//4//4.DXF", glm::mat4(1.0f), asShader);
	//std::vector<Shader> shaders;
	//shaders.push_back(asShader);
	//shaders.push_back(asShader);
	//shaders.push_back(asShader);
//	Game0::Sense sense0("Model//Mov", shaders);
//	Game0::Basic_Control_Sense csense("Model//1//1.obj", glm::mat4(1.0f), asShader);
//	Game0::Basic_Sense cmodel("Model//1//1.obj", glm::mat4(1.0f), asShader);
//	Game0::Movable_Sense csenses("Model//Mov",shaders);
//	Game0::Game game("Model//Static", "Model//Mov", shaders, shaders);
//	Game0::Game game("Model//Static", "Model//Mov");

//	__Background background(__Color(0.0f, 0.0f, 0.0f, 1.0f));
	AllControl::Sight sight("AllSight");
//	sight.InitSign();
	sight.InitSign();
	sight.Loop();
	//while (!glfwWindowShouldClose(window.Use()))
	//{
	//	camera.ProcessInput(window);
	//	background.Use(); 
	//	glClear(GL_DEPTH_BUFFER_BIT);
	//	game.UpdateCamera(camera);
	//	game.DrawGame();

	//	glfwSwapBuffers(window.Use());
	//	glfwPollEvents();
	//}
	glfwTerminate();
	return 0;
}