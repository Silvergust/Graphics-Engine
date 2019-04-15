#pragma once
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <string>

class Window
{
public:
	Window();
	~Window();

	void create(std::string title, int width, int height);

	bool shouldClose();

	void swapBuffers();
private:
	std::string _title;
	int _width, _height;

	GLFWwindow* _glfwWindow;
};

