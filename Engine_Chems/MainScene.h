#pragma once
#include "Scene.h"
#include "Objeto.h"
#include <gtc\matrix_transform.hpp>

class MainScene : public Scene
{
public:
	glm::vec3 eye = glm::vec3 (0,0,0);
	glm::vec3 target = glm::vec3 (0,0,1);
	glm::mat4  camera = lookAt(eye, target, glm::vec3(0.0f, 1.0f, 1.0f));

	MainScene();
	void start() final;
	void update() final;
	void draw() final;
	void destroyScene() final;
	Objeto *triangle;
	
	Shader *frag, *vert;
	ShaderProgram *prog;

	~MainScene();
	

};
