#include <iostream>
#include <fstream>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Mesh.h"



Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::import(std::string filePath) {
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(filePath, aiProcess_Triangulate);


}
