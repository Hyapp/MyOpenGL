#include "All.h"
#include"Sense1Control.h"

AllControl::Sight::Sight(const std::string & path)
{
	auto temp = path + "//title.txt";
	std::fstream titleFile(temp);
	std::string line;
	auto t = SightIndex::allSight;
	while (titleFile >> line)
	{
		temp = path + "//" + line;
		this->gamePaths.push_back(temp);
	}
}

bool AllControl::Sight::InitSign()
{
	MyOpenGL::GLFWInitialization::GLFWInit(4, 5);
	this->window = std::make_unique<MyOpenGL::_CreateWindow>(1000, 1000, "Design0");
	if (!window->Use())
	{
		std::cout << "Failed to create window!" << std::endl;
		this->window.reset(nullptr);
		std::cout << "Error::Can't initial sight" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(window->Use());
	MyOpenGL::_GLADInitialization glad;
	if (!glad.Available())
	{
		std::cout << "Failed to create glad!" << std::endl;
		this->window.reset(nullptr);
		std::cout << "Error::Can't initial sight" << std::endl;
		return false;
	}
	glEnable(GL_DEPTH_TEST);

	if (!LoadGame(0, 0))
	{
		std::cout << "Fail to load the all-time sight!" << std::endl;
		return false;
	}
	if (!LoadGame(1, 1))
	{
		std::cout << "Fail to load the sight1 !" << std::endl;
		return false;
	}
}

bool AllControl::Sight::LoadGame(unsigned int pathIndex, unsigned int gameIndex)
{
	switch (gameIndex)
	{
	case 0:
	{
		auto temp = this->gamePaths[pathIndex];
		auto staticPath = temp + "//Static";
		auto movPath = temp + "//Mov";
		this->allGame = std::make_unique<Game0::Game>(staticPath, movPath);
		return true;
		break;
	}
	case 1:
	{
		auto temp = this->gamePaths[pathIndex];
		auto staticPath = temp + "//Static";
		auto movPath = temp + "//Mov";
		this->currentGame = std::make_unique<Game0::Game>(staticPath, movPath);
		return true;
		break; 
	}
	case 2:
	{
		auto temp = this->gamePaths[pathIndex];
		auto staticPath = temp + "//Static";
		auto movPath = temp + "//Mov";
		this->lastGame = std::make_unique<Game0::Game>(staticPath, movPath);
		return true;
		break; 
	}
	case 3:
	{
		auto temp = this->gamePaths[pathIndex];
		auto staticPath = temp + "//Static";
		auto movPath = temp + "//Mov";
		this->nextGame = std::make_unique<Game0::Game>(staticPath, movPath);                 
		return true;
		break;
	}
	default:
	{
		std::cout << "Have no Buffer to load!" << std::endl;
		return false;
		break;
	}
	}
	return false;
}

void AllControl::Sight::Loop()
{
	while (currentChanged || !glfwWindowShouldClose(this->window->Use()))
	{
		GetKeyProcess();
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		auto projection = camera.Perspective(1000, 1000);
		auto view = camera.LookAt();

		for (auto & item : this->allGame->movableObjects.contralSenses)
		{
			item->UseShader().Use();
			item->SetProjectionMatrix(projection);
			item->SetViewMatrix(view);
		}
		for (auto & item :this->allGame->staticObjects.senses)
		{
			item->UseShader().Use();
			item->SetProjectionMatrix(projection);
			item->SetViewMatrix(view);
		}
		for (auto & item : this->currentGame->staticObjects.senses)
		{
			item->UseShader().Use();
			item->SetProjectionMatrix(projection);
			item->SetViewMatrix(view);
		}
		for (auto & item : this->currentGame->movableObjects.contralSenses)
		{
			item->UseShader().Use();
			item->SetProjectionMatrix(projection);
			item->SetViewMatrix(view);
		}
		this->allGame->DrawGame();
		this->currentGame->DrawGame();
		glfwSwapBuffers(window->Use());
		glfwPollEvents();
	}
}

void AllControl::Sight::GetKeyProcess()
{
	if (glfwGetKey(window->Use(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window->Use(), true);

	if (glfwGetKey(window->Use(), GLFW_KEY_W) == GLFW_PRESS)
		camera.SetCameraPos(camera.GetCameraPos() + camera.GetSpeed()*camera.GetCameraFront());

	if (glfwGetKey(window->Use(), GLFW_KEY_S) == GLFW_PRESS)
		camera.SetCameraPos(camera.GetCameraPos() - camera.GetSpeed()*camera.GetCameraFront());

	if (glfwGetKey(window->Use(), GLFW_KEY_A) == GLFW_PRESS)
		camera.SetCameraPos(camera.GetCameraPos() - glm::normalize(glm::cross(camera.GetCameraFront(), camera.GetCameraUp()))*camera.GetSpeed());

	if (glfwGetKey(window->Use(), GLFW_KEY_D) == GLFW_PRESS)
		camera.SetCameraPos(camera.GetCameraPos() + glm::normalize(glm::cross(camera.GetCameraFront(), camera.GetCameraUp()))*camera.GetSpeed());

	if (glfwGetKey(window->Use(), GLFW_KEY_UP) == GLFW_PRESS)
		this->currentGame->InputKey(Game0::KEY_VALUE::Up);
	if (glfwGetKey(window->Use(), GLFW_KEY_DOWN) == GLFW_PRESS)
		this->currentGame->InputKey(Game0::KEY_VALUE::Down);
	if (glfwGetKey(window->Use(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		this->currentGame->InputKey(Game0::KEY_VALUE::Right);
	if (glfwGetKey(window->Use(), GLFW_KEY_LEFT) == GLFW_PRESS)
		this->currentGame->InputKey(Game0::KEY_VALUE::Left);

	if (glfwGetKey(window->Use(), GLFW_KEY_F10) == GLFW_PRESS)
	{
		glfwSetInputMode(window->Use(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}
