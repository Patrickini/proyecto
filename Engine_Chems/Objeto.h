#pragma once
#include <glm.hpp>
#include "MeshOb.h"
#include "MeshMaterial.h"
#include <gtc\matrix_transform.hpp>

class Objeto
{
protected:
	MeshOb* mesh;
	MeshMaterial* material;
	
public:
	void draw();
	void setMesh(MeshOb* _mesh);
	void setMaterial(MeshMaterial* mat);
	void translate(glm::vec3 trans);
	void rotate(float angulo, glm::vec3 eje);
	void setScale(glm::vec3 scl);
	MeshMaterial* getMaterial() { return material; }
	glm::mat4 position, rotation, scale;
	Objeto();
	~Objeto();
};

