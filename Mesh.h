#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include <string>
#include "Material.h"

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

struct Texture {
	enum TextureType {Albedo, Metalicity, Roughness, Normal};

	GLint id;
	TextureType type;
};

class Mesh
{
public:
	Mesh();
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Material> materials);//std::vector<Texture> textures);
	~Mesh();

	std::vector<Vertex> getVertices() { return _Vertices; }

private:
	std::vector<Vertex> _Vertices;
	std::vector<GLuint> _Indices;
	std::vector<Material> _Materials;
	//std::vector<Texture> _Textures;

	void import(std::string filePath);
};

