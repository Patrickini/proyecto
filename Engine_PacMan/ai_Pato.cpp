#include "ai_Pato.h"
#include <gtc\type_ptr.hpp>
#include <tuple>
#include <gl\glew.h>
#include <GL\GLU.h>
#include <glm.hpp>
#include <stdarg.h>
#pragma comment(lib, "glu32")


void ai_Pato::setMaterialParam(int argc, ...)
{
	va_list list;
	va_start(list,argc);

	glm::mat4 m4 = *(glm::mat4*)va_arg(list,void*);
	glm::vec4 v4 = *(glm::vec4*)va_arg(list, void*);
	va_end(list);
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
