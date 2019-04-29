#include <iostream>
#include <fstream>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Mesh.h"
#include "Error.h"



Mesh::Mesh()
{
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
	_vertices = vertices;
	_indices = indices;
}


Mesh::~Mesh()
{
}

