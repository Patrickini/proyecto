#pragma once
#include<GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>
#include <vector>

class MeshOb
{
private:

	GLuint vbo;
	GLuint vao;
	GLuint ibo;
	GLuint uvbo;
	GLuint nbo;

	bool hasUV;
	bool hasNormals;
	bool isIndexed;

	int numVertex;
	int numIndex;

public:
	int getNumVertex();
	int getNumIndex();

	bool getHasUV();
	bool getHasNormals();
	bool getIsIndexed();

	void enableMesh();
	void LoadFromFile(std::string str);
	void LoadFromBase(std::vector<GLfloat> floatVec, std::vector<GLuint>* intVec,
		std::vector<GLfloat>* flatVec2, std::vector<GLfloat>*flatVec3);
	MeshOb();
	~MeshOb();
};

