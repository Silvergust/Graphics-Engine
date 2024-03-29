#include <iostream>
#include "Window.h"

#include <string>
#include <glm\glm.hpp>
#include "Shader.h"
#include "Model.h"
#include "Camera.h"

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

	/*GLfloat testTriangleVertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.0f,	0.5f, 0.0f,
		0.5f,	-1.0f, 0.0f
	};*/
	/*GLfloat testCubeVertices[] = {
		-0.5f, -0.5f, 1.0f,
		 0.5f, -0.5f, 1.0f,
		-0.5f,  0.5f, 1.0f,
		 0.5f,  0.5f, 1.0f,
		-0.5f,  0.5f, 1.0f,
		 0.5f,  -0.5f, 1.0f
	};*/

	Model* model = new Model();

	model->importModel("C:/Users/ernrm/source/repos/OpenGL 02/Debug/suzanne.obj");

	std::vector<Vertex> vertices = model->getMeshes()[0].getVertices();

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &(vertices[0]), GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(testCubeVertices),
	//	testCubeVertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);//BUFFER_OFFSET(0));
	//glEnableVertexAttribArray(vPosition);

	ShaderProgram program;
	program.setup("featureless.vs", "purple_flat.fs");

	Color clearColor = {
		clearColor.r = 0.1f,
		clearColor.g = 0.2f,
		clearColor.b = 0.8f,
		clearColor.a = 1.0f
	};
	window->setClearColor(clearColor);
	glCheckError();

	Camera camera = Camera(window);

	camera._Position = glm::vec3();

	int frameCount = 0;

	while (!window->shouldClose()) {
		glfwPollEvents();

		float frameFactor = frameCount * 0.001f;
		camera.cameraUpdate(window);

		window->clear();

		program.use();

		glm::mat4 view = camera.getViewMatrix();
		program.setUniform("viewMatrix", view);
		program.setUniform("projectionMatrix", camera.getProjectionMatrix());

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		glBindVertexArray(0);

		window->draw();
		glCheckError();
		frameCount++;
	}

	glfwTerminate();
	return 0;

}
