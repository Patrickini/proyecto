#pragma once
#include "Objeto.h"

class Camera : public Objeto
{

public:
	glm::mat4 cameraTranslate;
	glm::mat4 cameraTarget;
	void lookAt();
	Camera();
	~Camera();
};

