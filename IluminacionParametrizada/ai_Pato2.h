#pragma once
#include <GL\glew.h>
#include <fwd.hpp>
#include "MeshMaterial.h"
#include <GLFW\glfw3.h>
#include <GL\glew.h>
class ai_Pato2 :public  MeshMaterial
{
private:
	/*
		uniform mat4 mTransform;
		uniform mat4 camera;
		uniform mat4 perspective;

		uniform float fTime;
		uniform vec3 myLightPosition;
		uniform vec3 vEye;

		out vec4 color;
	*/
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
	ai_Pato2();
	~ai_Pato2();
};

