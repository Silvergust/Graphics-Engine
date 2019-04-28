#include <iostream>
#include "Window.h"

#include <string>
#include <glm\glm.hpp>
#include "Shader.h"

#include "Error.h"

#define BUFFER_OFFSET(offset) ((void *)(offset))

using namespace Engine;

enum Attrib_IDs { vPosition = 0 };

int main() {
	Window* window = new Window();
	window->create("Engine", 720, 480);

	//GLuint VAOs[1];
	GLuint vao, vbo;

	/*ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "flat.vs"},
		{ GL_FRAGMENT_SHADER, "flat.fs"},
		{ GL_NONE, NULL }
	};*/

	GLfloat testTriangleVertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.0f,	0.5f, 0.0f,
		0.5f,	-1.0f, 0.0f
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(testTriangleVertices),
		testTriangleVertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);

	ShaderProgram program;
	program.setup("pass_through.vs", "purple_flat.fs");

	Color clearColor = {
		clearColor.r = 0.1f,
		clearColor.g = 0.2f,
		clearColor.b = 0.8f,
		clearColor.a = 1.0f
	};
	window->setClearColor(clearColor);
	glCheckError();

	while (!window->shouldClose()) {
		glfwPollEvents();

		window->clear();

		program.use();

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		window->draw();
		glCheckError();
	}

	glfwTerminate();
	return 0;

}
