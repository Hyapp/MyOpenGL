#include"Game.h"

namespace Game0
{
	Basic_Control_Sense::Basic_Control_Sense(
		std::string const & modelPath, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader):
		model(ModelLoad::Model(modelPath)),shader(shader),worldTranslateMatrix(modelTransMatrix)
	{
		this->shader.ID = shader.ID;
	}

	Basic_Control_Sense::Basic_Control_Sense(
		std::string const & modelPath,
		const glm::mat4 & modelTransMatrix,
		const std::string & vertexShaderPath,
		const std::string & fragmentShaderPath)
		: model(ModelLoad::Model(modelPath)), worldTranslateMatrix(modelTransMatrix), shader(vertexShaderPath.c_str(), fragmentShaderPath.c_str())
	{
	}

	Basic_Control_Sense::Basic_Control_Sense(
		const ModelLoad::Model & model, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader) :
		model(model), shader(shader), worldTranslateMatrix(modelTransMatrix)
	{
		this->shader.ID = shader.ID;
	}

	void Basic_Control_Sense::Draw()
	{
		this->shader.SetMatrix4f("model", worldTranslateMatrix);
		this->shader.SetInt("texture_diffuse1", 0);
		this->model.Draw(shader);
	}

	MyOpenGL::Shader & Basic_Control_Sense::UseShader()
	{
		return this->shader;
	}

	void Basic_Control_Sense::SetModelMatrix(const glm::mat4 & value)
	{
		this->worldTranslateMatrix = value;
	}

	void Basic_Control_Sense::SetViewMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("view", value);
	}

	void Basic_Control_Sense::SetProjectionMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("projection", value);
	}

	void Basic_Control_Sense::PressLeft()
	{
	}

	void Basic_Control_Sense::PressRight()
	{
	}

	void Basic_Control_Sense::MouseMoved(float xpos, float ypos)
	{
	}

	void Basic_Control_Sense::PressKey(const KEY_VALUE key)
	{
		try
		{
			this->worldTranslateMatrix = this->keyControl.at(key)(this->worldTranslateMatrix);
		}
		catch (const std::out_of_range & excepter)
		{
			std::cout << "Pressed the undefined key!" << std::endl;
		}
	}

	void Basic_Control_Sense::SetKey(const KEY_VALUE key, glm::mat4(*Func)(const glm::mat4 &))
	{
		this->keyControl[key] = Func;
	}

	void Basic_Control_Sense::DeleteKey(const KEY_VALUE key)
	{
		this->keyControl.erase(key);
	}
}
