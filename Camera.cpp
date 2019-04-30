#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
}


Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(_position, _position + getFront(), getUp());
}

glm::vec3 Camera::getFront() {
	return glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 Camera::getUp() {
	return glm::vec3(0.0f, 1.0f, 0.0f);
}