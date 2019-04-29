#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
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

private:
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;

	void import(std::string filePath);
};

