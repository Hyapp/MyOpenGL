#include"Game.h"

namespace Game0 
{
	Basic_Sense::Basic_Sense
	(
		std::string const & modelPath, const glm::mat4 & modelTransMatrix,
		MyOpenGL::Shader shader
	) :
		model(ModelLoad::Model(modelPath)), worldTranslateMatrix(modelTransMatrix), shader(shader)
	{
	}

	Basic_Sense::Basic_Sense(
		std::string const & modelPath,
		const glm::mat4 & modelTransMatrix, 
		const std::string & vertexShaderPath,
		const std::string & fragmentShaderPath):

		model(ModelLoad::Model(modelPath)),
		worldTranslateMatrix(modelTransMatrix), 
		shader(MyOpenGL::Shader(vertexShaderPath,fragmentShaderPath))
	{
	}

	Basic_Sense::Basic_Sense
	(
		const ModelLoad::Model & model, const glm::mat4 & modelTransMatrix,
		MyOpenGL::Shader shader
	)
		: model(model), shader(shader)
	{
		worldTranslateMatrix = modelTransMatrix;
	}

	void Basic_Sense::Draw(void)
	{
		this->shader.Use();
		this->shader.SetMatrix4f("model", worldTranslateMatrix);
		this->shader.SetInt("texture_diffuse1", 0);
		this->model.Draw(shader);
	}

	MyOpenGL::Shader & Basic_Sense::UseShader()
	{
		return this->shader;
	}

	void Basic_Sense::SetModelMatrix(const glm::mat4 & value)
	{
		this->worldTranslateMatrix = value;
	}

	void Basic_Sense::SetViewMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("view", value);
	}

	void Basic_Sense::SetProjectionMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("projection", value);
	}

	void Basic_Sense::SetModel(const ModelLoad::Model & value)
	{
		this->model = value;
	}

	void Basic_Sense::SetModel(const std::string & modelPath)
	{
		this->model = ModelLoad::Model(modelPath);
	}

	void Basic_Sense::SetShader(const MyOpenGL::Shader & value)
	{
		this->shader = value;
	}

	void Basic_Sense::SetShader(const std::string & vertexPath, const std::string & fragmentPath)
	{
		this->shader = MyOpenGL::Shader(vertexPath.c_str(), fragmentPath.c_str());
	}
}