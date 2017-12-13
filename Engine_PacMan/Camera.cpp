#include "Camera.h"

void Camera::lookAt()
{
	glm::vec4 identity(1.0f);
	glm::vec3 eye;
	eye = (identity * Objeto::position);
	cameraTranslate = glm::lookAt(eye,cameraTarget,glm::vec3(0,1,0));
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
