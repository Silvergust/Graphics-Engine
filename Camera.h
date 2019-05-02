#pragma once

#include "Window.h"
#include <glm\glm.hpp>
#include <glm\gtc\quaternion.hpp>

namespace Engine {
	class Camera
	{
	public:
		Camera();
		Camera(Window* window);
		~Camera();

		glm::vec3 _Position = glm::vec3(0.0f);
		glm::vec3 _Orientation = glm::vec3(0.0f);

		void cameraUpdate(Window* window);

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

		glm::vec3 getFront();
		glm::vec3 getRight();
		glm::vec3 getUp();
	private:
		//TODO: Consider creating a PerspectiveCamera subclass.
		float _FOV = glm::radians(75.0f);
		float _AspectRatio = 1080.0f / 720.0f;
		float _MinClipDistance = 0.01;
		float _MaxClipDistance = 100;

		glm::mat4 _ProjectionMatrix;
	};
}