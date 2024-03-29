#pragma once
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "Color.h"
#include <string>

namespace Engine {
	enum Inputs { W, A, S, D };

	class Window
	{
	public:
		Window();
		~Window();

		void create(std::string title, int width, int height);

		bool shouldClose();

		void draw();

		void setClearColor(Color color);

		GLFWwindow* getGLFWWindow() { return _glfwWindow; }

		static void clear();

		bool IsKeyDown(Inputs inputKey);

	private:
		std::string _title;
		int _width, _height;

		GLFWwindow* _glfwWindow;
	};
}