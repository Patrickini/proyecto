#pragma once
#include "MeshOb.h"
#include "OBJ_Loader.h"
void MeshOb::LoadFromBase(std::vector<GLfloat> floatVec, std::vector<GLuint>* intVec,
	std::vector<GLfloat>* flatVec2, std::vector<GLfloat>*flatVec3)
{
	numVertex = floatVec.size() / 4;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	if (intVec != nullptr)
	{
		numIndex = intVec->size();
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, intVec->size() * sizeof(GLuint), &intVec->at(0), GL_STATIC_DRAW);
		isIndexed = true;
	}
	glBufferData(GL_ARRAY_BUFFER, (sizeof(GLfloat) * floatVec.size()), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * floatVec.size(), floatVec.data());
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

}

void MeshOb::LoadFromFile(std::string file)
{
	objl::Loader loader;
	std::vector<GLfloat> vertex;
	std::vector<GLuint> indexes;
	objl::Mesh mesh;
	int indexOffset = 0;
	bool result = loader.LoadFile(file);
	if (result)
	{
		for (int k = 0; k < loader.LoadedMeshes.size(); ++k)
		{
			mesh = loader.LoadedMeshes.at(k);
			for (int i = 0; i < mesh.Vertices.size(); ++i)
			{
				vertex.push_back(mesh.Vertices.at(i).Position.X);
				vertex.push_back(mesh.Vertices.at(i).Position.Y);
				vertex.push_back(mesh.Vertices.at(i).Position.Z);
				vertex.push_back(1);
			}
			indexOffset = 0;
			for (int i = 0; i < k; ++i)
				indexOffset += loader.LoadedMeshes.at(0).Vertices.size();
			for (int i = 0; i < mesh.Indices.size(); ++i)
			{
				indexes.push_back(indexOffset + mesh.Indices.at(i));
			}
		}
	}
	LoadFromBase(vertex, &indexes, nullptr, nullptr);
}
int MeshOb::getNumVertex() {
	return numVertex;
}
int MeshOb::getNumIndex() {
	return numIndex;
}
void MeshOb::enableMesh() {
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);

	if (isIndexed) {
		glDrawArrays(GL_TRIANGLES, 0, numVertex);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	}
}

bool MeshOb::getHasUV() {
	return hasUV;
}
bool MeshOb::getHasNormals(){
	return hasNormals;
}
bool MeshOb::getIsIndexed(){
	return isIndexed;
}

MeshOb::MeshOb() {

}
MeshOb::~MeshOb() {

}