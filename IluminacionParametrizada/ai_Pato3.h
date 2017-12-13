#pragma once
#include <GL\glew.h>
#include <fwd.hpp>
#include "MeshMaterial.h"
#include <GLFW\glfw3.h>
#include <GL\glew.h>

class ai_Pato3 :public  MeshMaterial
{
private:
	GLuint mTransform;
	GLuint camera;
	GLuint perspective;

	GLuint ftime;
	GLuint myLightPosition;
	GLuint vEye;
	GLuint color;

public:
	
	void setMaterialParam(glm::mat4 transform, glm::mat4 _camera, glm::mat4 _perspective, float _fTime, glm::vec3 _myLightPosition, glm::vec3 _vEye, glm::vec4 _color);
	void getMaterialParam() override;

	ai_Pato3();
	~ai_Pato3();
};

