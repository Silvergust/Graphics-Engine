#include <iostream>
#include "Window.h"

#include <string>

int main() {
	std::cout << "Hello world!" << std::endl;
	Window* window = new Window();
	window->create("Hello world!", 720, 480);


	while (!window->shouldClose()) {
		glfwPollEvents();

		
		window->draw();
		//std::cout << "tick" << std::endl;
	}

	glfwTerminate();
	return 0;

}