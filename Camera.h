#pragma once
#include <glm\glm.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	glm::vec3 _position;
	glm::vec3 _orientation;

	glm::mat4 getViewMatrix();
	glm::vec3 getFront();
	glm::vec3 getUp();
};

