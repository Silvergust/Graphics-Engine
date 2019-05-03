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

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Material> materials) {//std::vector<Texture> textures) {
	_Vertices = vertices;
	_Indices = indices;
	//_Textures = textures;
	_Materials = materials;
}


Mesh::~Mesh()
{
}

