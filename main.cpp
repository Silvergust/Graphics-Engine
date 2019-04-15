#include <iostream>
#include "Window.h"

#include <string>
//#define GLEW_STATIC
//#include "GL\glew.h"

int main() {
	std::cout << "Hello world!" << std::endl;
	Window* window = new Window();
	window->create("Hello world!", 720, 480);

	//glClearColor(0.7f, 0.5f, 0.3f, 1.0f);

	while (!window->shouldClose()) {
		window->swapBuffers();
		std::cout << "tick" << std::endl;
	}
	return 0;

}