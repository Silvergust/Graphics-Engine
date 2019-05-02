#include "Window.h"
#include <iostream>
#include <unordered_map>
#include "Error.h"

namespace Engine {
	Window::Window()
	{
	}

	Window::~Window()
	{
	}

	void Window::create(std::string title, int width, int height)
	{
		_title = title;
		_width = width;
		_height = height;

		int GLFWresult = glfwInit();
		if (!GLFWresult) {
			fatalError("glfwInit() error!");
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (_glfwWindow == NULL) {
			fatalError("glfwCreateWindow() error!");
		}

		glfwMakeContextCurrent(_glfwWindow);

		glewExperimental = GL_TRUE;
		GLenum GLEWresult = glewInit();
		if (GLEWresult != GLEW_OK) {
			fatalError("glewInit() error " + GLEWresult);
		}

		glClearColor(0.7f, 0.5f, 0.3f, 1.0f);
		glViewport(0, 0, _width, _height);
		glfwSetWindowTitle(_glfwWindow, _title.c_str());
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(_glfwWindow);
	}

	void Window::draw() {
		glfwSwapBuffers(_glfwWindow);
	}

	void Window::setClearColor(Color color) {
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	}

	//TODO: Consider moving to an input managing class
	static std::unordered_map<Inputs, int> _KeyDict = {
		{ W, GLFW_KEY_W },
		{ A, GLFW_KEY_A },
		{ S, GLFW_KEY_S },
		{ D, GLFW_KEY_D },
	};

	bool Window::IsKeyDown(Inputs inputKey) {
		bool value = glfwGetKey(_glfwWindow, _KeyDict[inputKey]) == GLFW_PRESS;
		return value;
	}
}