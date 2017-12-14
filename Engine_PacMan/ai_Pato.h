#pragma once
#include <GL\glew.h>
#include <fwd.hpp>
#include "MeshMaterial.h"
#include <GLFW\glfw3.h>
#include <GL\glew.h>

class ai_Pato :public  MeshMaterial
{
private:
	GLuint vColor;
	GLuint transform;

	
public:
	void setMaterialParam(int argc, ...) override;
	void getMaterialParam() override;
	ai_Pato();
	~ai_Pato();
};

