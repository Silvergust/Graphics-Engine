#include "Camera.h"
#include "Window.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <algorithm>

namespace Engine {
	const float SPEED = 0.01f;
	float mouseSensitivity = 0.01f;
	double startingScreenX;
	double startingScreenY;
	Camera* _CurrentCamera; //TODO: Fix the issue of C functions (glfwSetCursorPosCallback) not accepting a member's method.
	
	void panView(GLFWwindow* window, double xPos, double yPos);

	Camera::Camera()
	{
	}

	Camera::Camera(Window* window) {
		_ProjectionMatrix = glm::perspective(_FOV, _AspectRatio, _MinClipDistance, _MaxClipDistance);
		glfwGetCursorPos(window->getGLFWWindow(), &startingScreenX, &startingScreenY);
		glfwSetCursorPosCallback(window->getGLFWWindow(), panView);
		_CurrentCamera = this;
	}


	Camera::~Camera()
	{
	}

	void Camera::cameraUpdate(Window* window) {
		////FPS camera controls
		if (window->IsKeyDown(W)) {
			_Position += getFront() * SPEED;
		}
		else if (window->IsKeyDown(S)) {
			_Position -= getFront() * SPEED;
		}

		if (window->IsKeyDown(A)) {
			_Position -= getRight() * SPEED;
		}
		else if (window->IsKeyDown(D)) {
			_Position += getRight() * SPEED;
		}
	}

	void panView(GLFWwindow* window, double xPos, double yPos) {
		int width;
		int height;
		glfwGetWindowSize(window, &width, &height);
		double deltaX = (xPos - width * 0.5f)*mouseSensitivity;
		double deltaY = (yPos - height * 0.5f)*mouseSensitivity;

		_CurrentCamera->_Orientation = glm::vec3(deltaX, -deltaY, 0.0f);
	}

	glm::mat4 Camera::getViewMatrix() {
		return glm::lookAt(_Position, _Position + getFront(), getUp());
	}

	glm::mat4 Camera::getProjectionMatrix() {
		return _ProjectionMatrix;
	}

	glm::vec3 Camera::getFront() {
		glm::vec3 frontVector = glm::vec3(  cos(_Orientation.x) * cos(_Orientation.y),
											sin(_Orientation.y),
											sin(_Orientation.x) * cos(_Orientation.y));// *_Orientation;
		return frontVector;
	}

	glm::vec3 Camera::getRight() {
		return glm::normalize(glm::cross(getFront(), getUp()));
	}

	glm::vec3 Camera::getUp() {
		return glm::vec3(0.0f, 1.0f, 0.0f);
	}
}