#include <iostream>
#include "Window.h"

#include <string>
#include <glm\glm.hpp>
#include "Shader.h"

#define BUFFER_OFFSET(offset) ((void *)(offset))

using namespace Engine;

enum Attrib_IDs { vPosition = 0 };

int main() {
	std::cout << "Hello world!" << std::endl;
	Window* window = new Window();
	window->create("Hello world!", 720, 480);

	//GLuint VAOs[1];
	GLuint vao, vbo;

	/*ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "flat.vs"},
		{ GL_FRAGMENT_SHADER, "flat.fs"},
		{ GL_NONE, NULL }
	};*/

	GLfloat testTriangleVertices[] = {
		-0.5f, -0.5f,
		0.0f,	0.5f,
		0.5f,	-0.5f
	};

	ShaderProgram program;

	program.setup("pass_through.vs", "purple_flat.fs");

	while (!window->shouldClose()) {
		glfwPollEvents();

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(testTriangleVertices),
			testTriangleVertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

		glEnableVertexAttribArray(vPosition);

		program.use();

		window->draw();
		//std::cout << "tick" << std::endl;
	}

	glfwTerminate();
	return 0;

}
