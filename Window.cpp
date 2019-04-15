#include "Window.h"
#include <iostream>
#include "Error.h"

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
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(_glfwWindow);
}

void Window::swapBuffers() {
	glfwSwapBuffers(_glfwWindow);
}