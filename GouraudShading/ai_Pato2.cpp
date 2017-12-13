#include "ai_Pato2.h"
#include <gtc\type_ptr.hpp>
#include <tuple>
#include <gl\glew.h>
#include <GL\GLU.h>
#include <glm.hpp>
#pragma comment(lib, "glu32")
/*
	uniform mat4 mTransform;
	uniform mat4 camera;
	uniform mat4 perspective;

	uniform float fTime;
	uniform vec3 myLightPosition;
	uniform vec3 vEye;

	out vec4 color;
*/

void ai_Pato2::setMaterialParam(glm::mat4 transform, glm::mat4 _camera, glm::mat4 _perspective, float _fTime, glm::vec3 _myLightPosition, glm::vec3 _vEye, glm::vec4 _color)
{
	glm::mat4 m4 = transform;
	glm::mat4 cam = _camera;
	glm::mat4 persp = _perspective;
	float T = _fTime;
	glm::vec3 light = _myLightPosition;
	glm::vec3 eye = _vEye;
	glm::vec4 v4 = _color;
	glUniformMatrix4fv(mTransform, 1, GL_FALSE, glm::value_ptr(m4));
	glUniformMatrix4fv(camera, 1, GL_FALSE, glm::value_ptr(cam));
	glUniformMatrix4fv(perspective, 1, GL_FALSE, glm::value_ptr(persp));
	glUniform1fv(ftime, 1, &T);
	glUniform3fv(myLightPosition, 1, glm::value_ptr(light));
	glUniform3fv(vEye, 1, glm::value_ptr(eye));
	glUniform4fv(color, 1, glm::value_ptr(v4));
}

void ai_Pato2::getMaterialParam()
{
	color = glGetUniformLocation(program->getProgram(), "color");
	vEye = glGetUniformLocation(program->getProgram(), "vEye");
	myLightPosition = glGetUniformLocation(program->getProgram(), "myLightPosition");
	ftime = glGetUniformLocation(program->getProgram(), "fTime");
	perspective = glGetUniformLocation(program->getProgram(), "perspective");
	camera = glGetUniformLocation(program->getProgram(), "camera");
	mTransform = glGetUniformLocation(program->getProgram(), "mTransform");

}

ai_Pato2::ai_Pato2()
{
}


ai_Pato2::~ai_Pato2()
{
}