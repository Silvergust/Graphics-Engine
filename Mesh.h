#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>

struct Vertex {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 normal = glm::vec3(0.0f, 0.0f, 0.0f);
	union {
		glm::vec2 uv;
		struct {
			GLfloat u;
			GLfloat v;
		};
	};
};

class Mesh
{
public:
	Mesh();
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	~Mesh();

	std::vector<Vertex> getVertices() { return _vertices; }

private:
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;

	void import(std::string filePath);
};

