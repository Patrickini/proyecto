#include "Camera.h"

void Camera::lookAt()
{
	glm::vec4 identity(1.0f);
	glm::vec3 eye, target;
	eye = (identity * Objeto::position);
	target = (identity * cameraTarget);
	cameraTranslate = glm::lookAt(eye,target,glm::vec3(0,1,0));
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
