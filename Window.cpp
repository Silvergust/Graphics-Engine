#include "Window.h"
#include <iostream>
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
		glfwSetWindowTitle(_glfwWindow, "Test");
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(_glfwWindow);
	}

	void Window::draw() {
		glClearColor(0.1f, 0.8f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(_glfwWindow);
	}

	//void Window::SetClearColor() {
	//
	//}
}