#pragma once
#include "Objeto.h"

class Camera : public Objeto
{

public:
	glm::mat4 cameraTranslate;
	glm::vec3 cameraTarget;
	glm::mat4 cameraPerspective;
	void lookAt();
	Camera();
	~Camera();
};

