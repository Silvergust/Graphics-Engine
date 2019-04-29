#pragma once

#include <string>
#include <vector>
#include "Mesh.h"

class Model
{
public:
	Model();
	~Model();

	void import(std::string filePath);

private:
	std::string _filePath;
	std::vector<Mesh> _meshes;

	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};

