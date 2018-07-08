#pragma once
#include"Game.h"

namespace Sense1Contral
{
	glm::mat4 Up(const glm::mat4 & value)
	{
		return glm::translate(value, glm::vec3(0, 1, 0));
	}
	glm::mat4 Down(const glm::mat4 & value)
	{
		return glm::translate(value, glm::vec3(0, -1, 0));
	}
	glm::mat4 Ru(const glm::mat4 & value)
	{
		return glm::rotate(value, glm::radians(5.0f), glm::vec3(1, 0, 0));
	}
	glm::mat4 Ro(const glm::mat4 & value)
	{
		return glm::rotate(value, glm::radians(5.0f), glm::vec3(0, 1, 0));
	}
}

namespace CallBack 
{

}