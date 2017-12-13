#include "ai_Pato.h"
#include <gtc\type_ptr.hpp>
#include <tuple>
#include <gl\glew.h>
#include <GL\GLU.h>
#include <glm.hpp>
#pragma comment(lib, "glu32")


void ai_Pato::setMaterialParam(glm::mat4 matrix4, glm::vec4 vector3)
{
	glm::mat4 m4 = matrix4;
	glm::vec4 v4 = vector3;
	glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(m4));
	glUniform4fv(vColor, 1, glm::value_ptr(v4));
}

void ai_Pato::getMaterialParam()
{
	vColor = glGetUniformLocation(program->getProgram(), "vColor");
	transform = glGetUniformLocation(program->getProgram(), "transform");

}

ai_Pato::ai_Pato()
{
}


ai_Pato::~ai_Pato()
{
}
