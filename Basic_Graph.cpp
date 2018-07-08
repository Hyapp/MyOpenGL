#include"Game.h"

namespace Game0
{
	void Basic_Graph::Ready()
	{
		if (this->buffer)
		{
			vertex.ReBind();
			this->buffer->ReBind();
			if (dataField < 3)
			{
				for (size_t i = 0; i < dataField; i++)
				{
					MyOpenGL::_VertexAttrubPoint(i, 3, dataSize, (void*)(i * 3 * sizeof(float)));
				}
			}
			else
			{
				MyOpenGL::_VertexAttrubPoint(0, 3, dataSize, (void*)(0 * 3 * sizeof(float)));
				MyOpenGL::_VertexAttrubPoint(1, 3, dataSize, (void*)(1 * 3 * sizeof(float)));
				MyOpenGL::_VertexAttrubPoint(2, 2, dataSize, (void*)(2 * 3 * sizeof(float)));
			}
			shader.Use();
			shader.SetInt("texture_diffuse1", 0);
		}
	}

	Basic_Graph::Basic_Graph
	(
		unsigned int vertexNum, unsigned int dataSize, unsigned int dataField,
		float * datas, const MyOpenGL::_Texture2D & texture, MyOpenGL::Shader & shader,
		const glm::mat4 & value
	) :texture(texture), shader(shader)
	{
		this->vertexNum = vertexNum;
		this->dataSize = dataSize;
		this->dataField = dataField;
		this->datas = datas;
		worldTranslateMatrix = value;
		this->buffer = std::make_unique<MyOpenGL::_ArrayBuffer>(dataSize * vertexNum, datas, MyOpenGL::_GL_PLOT_WAY::static_draw);
		Ready();
	}

	Basic_Graph::Basic_Graph
	(
		unsigned int vertexNum, unsigned int dataSize, unsigned int dataField,
		float * datas, const std::string & texturePath, MyOpenGL::Shader & shader,
		const glm::mat4 & value
	)
		: texture(MyOpenGL::_Texture2D(texturePath)), shader(shader)
	{
		this->vertexNum = vertexNum;
		this->dataSize = dataSize;
		this->dataField = dataField;
		this->datas = datas;
		worldTranslateMatrix = value;
		this->buffer = std::make_unique<MyOpenGL::_ArrayBuffer>(dataSize * vertexNum, datas, MyOpenGL::_GL_PLOT_WAY::static_draw);
		Ready();
	}

	void Basic_Graph::SetModelMatrix(const glm::mat4 & value)
	{
		this->worldTranslateMatrix = value;
	}

	void Basic_Graph::SetViewMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("view", value);
	}

	void Basic_Graph::SetProjectionMatrix(const glm::mat4 & value)
	{
		this->shader.SetMatrix4f("projection", value);
	}

	MyOpenGL::Shader & Basic_Graph::UseShader()
	{
		return this->shader;
		// TODO: 在此处插入 return 语句
	}

	void Basic_Graph::Draw()
	{
		shader.Use();
		if (dataField == 3)
		{
			texture.ReBind();
		}
		shader.SetMatrix4f("model", worldTranslateMatrix);
		vertex.ReBind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}