#pragma once
#include"Boost.h"
#include"Graphics.h"
#include<utility>
#include<memory>
#include"OpenGL.h"
#include"AssimpModelLoad.h"
#include<set>

namespace Game0
{
	class Basic_Draw
	{
	public:
		virtual void Draw() = 0;
		virtual void SetModelMatrix(const glm::mat4 & value) = 0;
		virtual void SetViewMatrix(const glm::mat4 & value) = 0;
		virtual void SetProjectionMatrix(const glm::mat4 & value) = 0;
		virtual MyOpenGL::Shader & UseShader() = 0;
	};

	class Basic_Mouse_Press 
	{
	public:
		virtual void PressLeft() = 0;
		virtual void PressRight() = 0;
	};

	class Basic_Mouse_Move
	{
	public:
		virtual void MouseMoved(float xpos, float ypos) = 0;
	};

	class Basic_Mouse_Control :public Basic_Mouse_Press, public Basic_Mouse_Move
	{
	};

	class Basic_Key_Function
	{
		friend class Basic_Mouse_Control;
	public:
		Basic_Key_Function() {};
		Basic_Key_Function(glm::mat4(*Func)(const glm::mat4 &))
		{
			this->Func = Func;
		}
		bool SetFunc(glm::mat4(*Func)(const glm::mat4 &)) 
		{
			this->Func = Func;
		}
		glm::mat4 operator()(const glm::mat4 & value) const 
		{
			return Func(value);
		}
	private:
		glm::mat4(*Func)(const glm::mat4 & value) = nullptr;
	};

	enum class KEY_VALUE
	{
		Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L, Z, X, C, V, B, N, M,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, 
		Up, Down, Left, Right
	};

	class Basic_Key_Control :public Basic_Draw
	{
	public:
		virtual void PressKey(const KEY_VALUE key) = 0;
		virtual void SetKey(const KEY_VALUE key, glm::mat4(*Func)(const glm::mat4 &)) = 0;
		virtual void DeleteKey(const KEY_VALUE key) = 0;
	};

	class Basic_Control_Sense : public Basic_Key_Control, public Basic_Mouse_Control
	{
		friend class Contral_Sense;
	public:
		Basic_Control_Sense(std::string const & modelPath, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader);
		Basic_Control_Sense(std::string const & modelPath, const glm::mat4 & modelTransMatrix,
			const std::string & vertexShaderPath, const std::string & fragmentShaderPath);
		Basic_Control_Sense(const ModelLoad::Model & model, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader);

		//Basic_Key
		void PressKey(const KEY_VALUE key);
		void SetKey(const KEY_VALUE key, glm::mat4(*Func)(const glm::mat4 &));
		void DeleteKey(const KEY_VALUE key);

		//Basic_Draw
		void Draw();
		MyOpenGL::Shader & UseShader();
		void SetModelMatrix(const glm::mat4 & value);
		void SetViewMatrix(const glm::mat4 & value);
		void SetProjectionMatrix(const glm::mat4 & value);

		//Basic_Mouse
		void PressLeft();
		void PressRight();
		void MouseMoved(float xpos, float ypos);
	private:
		glm::vec3 pos;
		glm::vec3 front;
		glm::vec3 up;
		mutable glm::mat4 worldTranslateMatrix;
		ModelLoad::Model model;
		MyOpenGL::Shader shader;
		std::map<KEY_VALUE, Basic_Key_Function> keyControl;
	};

	class Basic_Graph :public Basic_Draw
	{
	public:
		Basic_Graph
		(
			unsigned int vertexNum, unsigned int dataSize, unsigned int dataField,
			float * datas, const MyOpenGL::_Texture2D &texture, MyOpenGL::Shader & shader,
			const glm::mat4 & value = glm::mat4(1.0f)
		);

		Basic_Graph
		(
			unsigned int vertexNum, unsigned int dataSize, unsigned int dataField,
			float * datas, const std::string & vertexPath, MyOpenGL::Shader & shader,
			const glm::mat4 & value = glm::mat4(1.0f)
		);

		void SetModelMatrix(const glm::mat4 & value);
		void SetViewMatrix(const glm::mat4 & value);
		void SetProjectionMatrix(const glm::mat4 & value);

		MyOpenGL::Shader & UseShader();
		void Draw();
		void Ready();
	private:
		MyOpenGL::Shader shader;
		float * datas;
		unsigned int vertexNum, dataField, dataSize;
		glm::mat4 worldTranslateMatrix;
		MyOpenGL::_Texture2D texture;

		MyOpenGL::_VertexReference vertex;
		std::unique_ptr<MyOpenGL::_ArrayBuffer> buffer = nullptr;
	};

	class Basic_Sense :public Basic_Draw
	{
	public:

		Basic_Sense(std::string const & modelPath, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader);
		Basic_Sense(std::string const & modelPath, const glm::mat4 & modelTransMatrix, const std::string & vertexShaderPath, const std::string & fragmentShaderPath);
		Basic_Sense(const ModelLoad::Model & model, const glm::mat4 & modelTransMatrix, MyOpenGL::Shader shader);

		//Basic_Draw
		void Draw(void);
		MyOpenGL::Shader & UseShader();
		void SetModelMatrix(const glm::mat4 & value);
		void SetViewMatrix(const glm::mat4 & value);
		void SetProjectionMatrix(const glm::mat4 & value);

		void SetModel(const ModelLoad::Model & value);
		void SetModel(const std::string & modelPath);
		void SetShader(const MyOpenGL::Shader & shader);
		void SetShader(const std::string & vertexPath, const std::string & fragmentPath);


	protected:
		MyOpenGL::Shader shader;
		ModelLoad::Model model;
		glm::mat4 worldTranslateMatrix;
	};

	//class ControlSense :public Basic_Key_Control,public Basic_Sense
	//{
	//public:
	//	ControlSense(std::string const & modelPath, const glm::mat4 & modelTransMatrix,
	//		const std::string & vertexShaderPath, const std::string & fragmentShaderPath);
	//	
	//	void PressKey(const KEY_VALUE key);
	//	void SetKey(const KEY_VALUE key, glm::mat4(*Func)(const glm::mat4 &));
	//	void DeleteKey(const KEY_VALUE key);
	//	void SetModelMatrix(const glm::mat4 & value);
	//	void SetViewMatrix(const glm::mat4 & value);
	//	void SetProjectionMatrix(const glm::mat4 & value);
	//protected:
	//};

	class Sense
	{
	public:
		Sense(const std::string & path, const std::vector<MyOpenGL::Shader> &shader);
		Sense(const std::string & path);
		~Sense();

		void PushBack(const Basic_Sense & value);
		void PopBack(void);

		void ReadGraph(const std::string & graphPath);

		void DrawSense();
		std::vector<std::shared_ptr<Basic_Draw>> senses;
	private:
		glm::mat4 GetMatrix4f(const std::string & path);
	};

	class Movable_Sense
	{
	public:
		Movable_Sense(const std::string & path, const std::vector<MyOpenGL::Shader> &shader);
		Movable_Sense(const std::string & path);

		void DrawSense();
		void PushBack(const Basic_Control_Sense & value);
		void PopBack(void);

		void ReadGraph(const std::string & graphPath);
		std::vector<std::shared_ptr<Basic_Key_Control>> contralSenses;
	private:
		glm::mat4 GetMatrix4f(const std::string & path);
	};

	class Game
	{
	public:
		Game(
			const std::string & staticObjectPath,
			const std::string & controlObjectPath,
			const std::vector<MyOpenGL::Shader> & staticShaders,
			const std::vector<MyOpenGL::Shader> & contralShaders
		);
		Game(
			const std::string & staticObjectPath,
			const std::string & controlObjectPath
		);

		~Game();

		void UpdateCamera(MyCamera::_Camera & camera);
		void DrawGame();
		void InputKey(const KEY_VALUE key);
		Movable_Sense movableObjects;
		Sense staticObjects;
	private:
	};
}