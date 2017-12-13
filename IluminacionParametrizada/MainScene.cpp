#pragma comment(lib, "glu32")
#include "Engine.h"
#include "MainScene.h"
#include "ai_Pato2.h"
#include "ai_Pato3.h"
#include <matrix.hpp>
#include <gtc\matrix_transform.hpp>
#include <gl\glew.h>
#include <GL\GLU.h>
#include <iostream>
#include <string>

MainScene::MainScene()
{

}


void MainScene::start()
{

	cube = new Objeto();
	MeshOb *cubeMesh = new MeshOb;
	ai_Pato2 *cubeMat = new ai_Pato2();
	ai_Pato3 *cubeMat2 = new ai_Pato3();
	cubeMesh->LoadFromFile("Wall.obj");

	CubeShaderProg = new ShaderProgram;
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("PhongShading.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("PhongShading.f");
	CubeShaderProg->setShaders(vert, frag, nullptr, nullptr);
	CubeShaderProg->createProgram();
	cubeMat->program = CubeShaderProg;

	CubeShaderProg2 = new ShaderProgram;
	vert2 = new Shader(Shadertype::vertex);
	vert2->loadFromFile("gouradPlane.v");
	frag2 = new Shader(Shadertype::fragment);
	frag2->loadFromFile("passThru.f");
	CubeShaderProg2->setShaders(vert2, frag2, nullptr, nullptr);
	CubeShaderProg2->createProgram();
	cubeMat2->program = CubeShaderProg2;

	//if (Engine::vertexString == "gouradPlane.v") {
	cube->setMaterial(cubeMat);
	cube->getMaterial()->getMaterialParam();
	cube->setMesh(cubeMesh);
	cube->getMaterial()->program->activateProgram();
	//}
	//if (Engine::vertexString == "PhongShading.v") {
	cube->setMaterial(cubeMat2);
	cube->getMaterial()->getMaterialParam();
	cube->setMesh(cubeMesh);
	cube->getMaterial()->program->activateProgram();
	//}
	cube->translate(glm::vec3(0, 0, 5));

	//glfwSetCursorPos(Engine::getWindow(), 640, 310);
	
	
}

void MainScene::update()
{
	
	/*
	if(Engine::startX < 640)
		cube->rotate(10.0f, glm::vec3(1, 0, 0));
	if (Engine::startX > 640)
		cube->rotate(-10.0f, glm::vec3(1, 0, 0));
	if (Engine::startY < 640)
		cube->rotate(10.0f, glm::vec3(0, 1, 0));
	if (Engine::startY > 640)
		cube->rotate(-10.0f, glm::vec3(0, 1, 0));
		*/
		
	//glfwSetCursorPos(Engine::getWindow(), 640, 310);
}

void MainScene::draw()
{
	//con keys: q y o
	if (Engine::vertexString == "gouradPlane.v") {
		((ai_Pato2*)cube->getMaterial())->setMaterialParam(cube->position*cube->rotation*cube->scale, camera, glm::perspective(45.0f, 1280.0f / 720.0f, .1f, 1000.0f), 3, glm::vec3(0, 1, 0), eye, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	}
	if (Engine::vertexString == "PhongShading.v") {
		((ai_Pato3*)cube->getMaterial())->setMaterialParam(cube->position*cube->rotation*cube->scale, camera, glm::perspective(45.0f, 1280.0f / 720.0f, .1f, 1000.0f), 3, glm::vec3(0, 1, 0), eye, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	}

	cube->draw();

}

void MainScene::destroyScene()
{

}


MainScene::~MainScene()
{

}
