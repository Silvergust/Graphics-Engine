#pragma once
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include <string>
#include <vector>
#include "Mesh.h"

class Model
{
public:
	Model();
	~Model();

	void importModel(std::string filePath);

	//GLfloat[] getVertices() { return }
	std::vector<Mesh> getMeshes() { return _meshes; }
private:
	std::string _filePath;
	std::vector<Mesh> _meshes;

	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};

