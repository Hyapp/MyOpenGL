#include"OpenGL.h"

namespace MyCamera
{
	_Camera::_Camera() :
		cameraPos(glm::vec3(0.0f, 0.0f, 3.0f)),
		cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
		cameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
	{}

	_Camera::_Camera(const glm::vec3 & cameraPos, const glm::vec3 & cameraFront, const glm::vec3 & cameraUp)
		:cameraPos(cameraPos), cameraFront(cameraFront), cameraUp(cameraUp)
	{}

	glm::mat4 _Camera::LookAt()
	{
		return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	glm::mat4 _Camera::Perspective(int scr_width, int scr_height)
	{
		return glm::perspective(glm::radians(fov), static_cast<float>(scr_width) / static_cast<float>(scr_height), _near, _far);
	}

	float _Camera::GetFov() const
	{
		return fov;
	}
	bool _Camera::SetFov(float value)
	{
		if (value > 0 && value < 360.f)
		{
			this->fov = value;
			return true;
		}
		else
			return false;
	}

	float _Camera::GetNear() const
	{
		return _near;
	}
	bool _Camera::SetNear(float value)
	{
		if (1)
		{
			this->_near = value;
			return true;
		}
		return false;
	}

	float _Camera::GetFar() const
	{
		return _far;
	}
	bool _Camera::SetFar(float value)
	{
		if (1)
		{
			this->_far = value;
			return true;
		}
		return false;
	}

	glm::vec3 _Camera::GetCameraPos(void) const
	{
		return this->cameraPos;
	}
	bool _Camera::SetCameraPos(const glm::vec3 & value)
	{
		if (1)
		{
			cameraPos = value;
			return true;
		}
		return false;
	}

	glm::vec3 _Camera::GetCameraFront(void) const
	{
		return this->cameraFront;
	}
	bool _Camera::SetCameraFront(const glm::vec3 & value)
	{
		if (1)
		{
			cameraFront = value;
			return true;
		}
		return false;
	}

	glm::vec3 _Camera::GetCameraUp(void) const
	{
		return this->cameraUp;
	}
	bool _Camera::SetCameraUp(const glm::vec3 & value)
	{
		if (1)
		{
			cameraUp = value;
			return true;
		}
		return false;
	}

	float _Camera::GetSpeed(void) const
	{
		return speed;
	}
	bool _Camera::SetSpeed(float value)
	{
		this->speed = value;
		return true;
	}

	void _Camera::ProcessInput(GLFWwindow * window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		//	camera.SetCameraPos(camera.GetCameraPos() + camera.GetSpeed()*camera.GetCameraFront());
			cameraPos += speed * cameraFront;

		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		//	camera.SetCameraPos(camera.GetCameraPos() - camera.GetSpeed()*camera.GetCameraFront());
			cameraPos -= speed * cameraFront;

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		//	camera.SetCameraPos(camera.GetCameraPos() - glm::normalize(glm::cross(camera.GetCameraFront(), camera.GetCameraUp()))*camera.GetSpeed());
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;

		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		//	camera.SetCameraPos(camera.GetCameraPos() + glm::normalize(glm::cross(camera.GetCameraFront(), camera.GetCameraUp()))*camera.GetSpeed());
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed;

		if (glfwGetKey(window,GLFW_KEY_F10) == GLFW_PRESS)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	}

	void _Camera::ProcessInput(const MyOpenGL::_CreateWindow & window)
	{
		ProcessInput(window.Use());
	}
}