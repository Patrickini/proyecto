#pragma comment(lib, "glu32")
#include "Engine.h"
#include "MainScene.h"
#include "ai_Pato.h"
#include <matrix.hpp>
#include <gtc\matrix_transform.hpp>
#include <gl\glew.h>
#include <GL\GLU.h>
#include <iostream>

MainScene::MainScene()
{

}

void MainScene::start()
{

	cube = new Objeto();
	MeshOb *cubeMesh = new MeshOb;
	ai_Pato *cubeMat = new ai_Pato();
	cubeMesh->LoadFromFile("Piso.obj");

	CubeShaderProg = new ShaderProgram;
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("shader.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("shader.f");
	CubeShaderProg->setShaders(vert, frag, nullptr, nullptr);
	CubeShaderProg->createProgram();
	cubeMat->program = CubeShaderProg;

	cube->setMaterial(cubeMat);
	cube->getMaterial()->getMaterialParam();
	cube->setMesh(cubeMesh);
	cube->getMaterial()->program->activateProgram();

	cube->translate(glm::vec3(0, 0, 5));

	//glfwSetCursorPos(Engine::getWindow(), 640, 310);
	
	
}

void MainScene::update()
{
	if(Engine::startX < 640)
		cube->rotate(10.0f, glm::vec3(1, 0, 0));
	if (Engine::startX > 640)
		cube->rotate(-10.0f, glm::vec3(1, 0, 0));
	if (Engine::startY < 640)
		cube->rotate(10.0f, glm::vec3(0, 1, 0));
	if (Engine::startY > 640)
		cube->rotate(-10.0f, glm::vec3(0, 1, 0));


	glfwSetCursorPos(Engine::getWindow(), 640, 310);
}

void MainScene::draw()
{
	((ai_Pato*)cube->getMaterial())->setMaterialParam(glm::perspective(45.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*cube->position*cube->rotation*cube->scale, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	cube->draw();

}

void MainScene::destroyScene()
{

}


MainScene::~MainScene()
{

}
