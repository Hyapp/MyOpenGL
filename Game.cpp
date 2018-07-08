#include"Game.h"

namespace Game0 
{
	Game::Game(
		const std::string & staticObjectPath,
		const std::string & controlObjectPath,
		const std::vector<MyOpenGL::Shader>& staticShaders,
		const std::vector<MyOpenGL::Shader>& controlShaders) :

		movableObjects(controlObjectPath, controlShaders),
		staticObjects(staticObjectPath, staticShaders)
	{
	}
	Game::Game(const std::string & staticObjectPath, const std::string & controlObjectPath)
		:movableObjects(controlObjectPath), staticObjects(staticObjectPath)
	{

	}
	Game::~Game()
	{
	}

	void Game::UpdateCamera(MyCamera::_Camera & camera)
	{
		auto projection = camera.Perspective(1000, 1000);
		auto view = camera.LookAt();
		for (auto & item :staticObjects.senses)
		{
			item->UseShader().Use();
			item->UseShader().SetMatrix4f("projection", projection);
			item->UseShader().SetMatrix4f("view", view);
		}
		for (auto & item : movableObjects.contralSenses)
		{
			item->UseShader().Use();
			item->UseShader().SetMatrix4f("projection", projection);
			item->UseShader().SetMatrix4f("view", view);
		}
	}

	void Game::DrawGame()
	{
		staticObjects.DrawSense();
		movableObjects.DrawSense();
	}
	void Game::InputKey(const KEY_VALUE key)
	{
		for (auto & item: movableObjects.contralSenses)
		{
			item->PressKey(key);
		}
	}
}