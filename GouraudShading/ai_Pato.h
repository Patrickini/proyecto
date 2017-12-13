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
	void setMaterialParam(glm::mat4 transform, glm::vec4 color);
	void getMaterialParam() override;
	ai_Pato();
	~ai_Pato();
};

