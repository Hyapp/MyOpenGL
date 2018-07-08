#include"Game.h"

namespace Game0 
{
	Movable_Sense::Movable_Sense(const std::string & path, const std::vector<MyOpenGL::Shader> &shader)
	{
		std::fstream file(path + "//title.txt");
		size_t num = 0;
		file >> num;
		for (size_t i = 0; i < num; i++)
		{
			auto temp = std::to_string(i + 1);
			auto objPath = path + "//" + temp + "//" + temp + ".obj";
			auto matPath = path + "//" + temp + "//" + temp + ".txt";
			const auto worldMatrix = GetMatrix4f(matPath);
			const auto model = ModelLoad::Model(objPath);
			PushBack(Basic_Control_Sense(model, worldMatrix, shader[i]));
		}
	}

	Movable_Sense::Movable_Sense(const std::string & path)
	{
		std::fstream file(path + "//title.txt");
		size_t num = 0;
		file >> num;
		for (size_t i = 0; i < num; i++)
		{
			auto temp = std::to_string(i + 1);
			auto            objPath = path + "//" + temp + "//" + temp + ".obj";
			auto            matPath = path + "//" + temp + "//" + temp + ".txt";
			auto   vertexShaderPath = path + "//" + temp + "//" + temp + ".vs";
			auto fragmentShaderPath = path + "//" + temp + "//" + temp + ".fs";
			auto worldMatrix = GetMatrix4f(matPath);

			PushBack(Basic_Control_Sense(objPath, worldMatrix, vertexShaderPath, fragmentShaderPath));
		}
	}

	void Movable_Sense::DrawSense()
	{
		for (auto & item : contralSenses)
		{
			item->UseShader().Use();
			item->Draw();
		}
	}

	void Movable_Sense::PushBack(const Basic_Control_Sense & value)
	{
		this->contralSenses.push_back(std::make_shared<Basic_Control_Sense>(value));
	}

	void Movable_Sense::PopBack(void)
	{
		this->contralSenses.pop_back();
	}

	void Movable_Sense::ReadGraph(const std::string & graphPath)
	{
	}

	glm::mat4 Movable_Sense::GetMatrix4f(const std::string & path)
	{
		std::fstream file(path);
		std::vector<float> temp;
		float value;
		while (!file)
		{
			file >> value;
			temp.push_back(value);
		}
		if (16 == temp.size())
		{
			return glm::mat4(
				glm::vec4(temp[0], temp[1], temp[2], temp[3]),
				glm::vec4(temp[4], temp[5], temp[6], temp[7]),
				glm::vec4(temp[8], temp[9], temp[10], temp[11]),
				glm::vec4(temp[12], temp[13], temp[14], temp[15])
			);
		}
		else
		{
			return glm::mat4(1.0f);
		}
	}


}