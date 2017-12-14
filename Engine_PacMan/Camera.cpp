#include "Camera.h"
#include "gtx\matrix_decompose.hpp"
void Camera::lookAt()
{
	glm::vec3 eye = glm::vec3(Objeto::position[3].x, Objeto::position[3].y, Objeto::position[3].z);
	cameraTranslate = glm::lookAt(eye,cameraTarget,glm::vec3(0,-1,0));
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
