#pragma once
#include "ShaderProgram.h"

class MeshMaterial
{
public:
	virtual void getMaterialParam() = 0;
	virtual void setMaterialParam(int argc, ...) = 0;
	ShaderProgram* program;
	MeshMaterial();
	~MeshMaterial();
};

