#include "Error.h"
#include <iostream>

#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

void fatalError(std::string string) {
	std::cout << string << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	glfwTerminate();
	exit(69);
}