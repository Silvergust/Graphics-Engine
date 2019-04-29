#include "Model.h"
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Error.h"


Model::Model()
{
}


Model::~Model()
{
}

void Model::import(std::string filePath) {
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(filePath, aiProcess_Triangulate);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		warning("Failed to read scene file.");
		return;
	}

	_filePath = filePath.substr(0, filePath.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}


void Model::processNode(aiNode *node, const aiScene *scene) {
	for (unsigned int i = 0; i < node->mNumMeshes; i++) {
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		_meshes.push_back(processMesh(mesh, scene));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) {
	std::vector<Vertex> vertices;
	//std::vector<Texture> textures;
	
	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
		Vertex vertex;
		//TODO: Create an operator override to assign these using aiVector3Ds
		vertex.position.x = mesh->mVertices[i].x;
		vertex.position.y = mesh->mVertices[i].y;
		vertex.position.z = mesh->mVertices[i].z;
		vertices.push_back(vertex);

		if (mesh->mTextureCoords[0]) {
			vertex.u = mesh->mTextureCoords[0][i].x;
			vertex.v = mesh->mTextureCoords[0][i].y;
		}
	}

	std::vector<unsigned int> indices;
	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++) {
			indices.push_back(face.mIndices[j]);
		}
	}

	/*if (mesh->mMaterialIndex >= 0) {

	}*/

	return Mesh(vertices, indices);
}