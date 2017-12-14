#include "Objeto.h"
#include <gl\glew.h>
#include <GL\GLU.h>
#include "Engine.h"


void Objeto::draw()
{
	if (isActive) {

		material->program->activateProgram();
		mesh->enableMesh();
		if (mesh->getIsIndexed()) {
			glDrawElements(GL_TRIANGLES, mesh->getNumIndex(), GL_UNSIGNED_INT, 0);
		}
		else {
			glDrawArrays(GL_TRIANGLES, 0, mesh->getNumVertex());
		}
	}
}

void Objeto::setMesh(MeshOb * _mesh)
{
	mesh = _mesh;
}

void Objeto::setMaterial(MeshMaterial * mat)
{
	material = mat;
}

void Objeto::translate(glm::vec3 trans)
{
	position = glm::translate(position, trans);
}

void Objeto::rotate(float angulo, glm::vec3 eje)
{
	float angulo_t = glm::radians(angulo);
	rotation = glm::rotate(rotation, angulo_t, eje);
}

void Objeto::setScale(glm::vec3 scl)
{
	scale = glm::scale(scale, scl);
}

void Objeto::setActive(bool isAct)
{
	isActive = isAct;
}

glm::mat4 Objeto::doTransformations()
{
	(*Engine::mainCamera)->lookAt();
	return (*Engine::mainCamera)->cameraPerspective * (*Engine::mainCamera)->cameraTranslate * position * rotation * scale;
}

Objeto::Objeto() : position(glm::mat4(1.0f)), rotation(glm::mat4(1.0f)), scale(glm::mat4(1.0f))
{
}


Objeto::~Objeto()
{
}
