#pragma comment(lib, "glu32")
#include "Engine.h"
#include "MainScene.h"
#include "ai_Pato2.h"
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
	ai_Pato2 *cubeMat = new ai_Pato2();
	cubeMesh->LoadFromFile("Wall.obj");

	CubeShaderProg = new ShaderProgram;
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("gouradPlane.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("passThru.f");
	CubeShaderProg->setShaders(vert, frag, nullptr, nullptr);
	CubeShaderProg->createProgram();
	cubeMat->program = CubeShaderProg;
	cube->setMaterial(cubeMat);
	cube->getMaterial()->getMaterialParam();
	cube->setMesh(cubeMesh);
	cube->getMaterial()->program->activateProgram();


	/*triangle = new Objeto();
	MeshOb *mesh = new MeshOb();
	ai_Pato *material = new ai_Pato();
	mesh->LoadFromFile("meshLocochon.obj");
	
	prog = new ShaderProgram();
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("shader.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("shader.f");
	prog->setShaders(vert, frag, nullptr, nullptr);
	prog->createProgram();
	material->program = prog;
	triangle->setMaterial(material);
	triangle->getMaterial()->getMaterialParam();
	triangle->setMesh(mesh);
	triangle->getMaterial()->program->activateProgram();
	triangle->translate(glm::vec3(0, 0, 100));*/
	cube->translate(glm::vec3(0, 0, 10));
	
}

void MainScene::update()
{
	if(Engine::anguloH)
		cube->rotate(10.0f, glm::vec3(1, 0, 0));
}

void MainScene::draw()
{
	//((ai_Pato2*)cube->getMaterial())->setMaterialParam(glm::perspective(45.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*cube->position*cube->rotation*cube->scale,glm:: glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	((ai_Pato2*)cube->getMaterial())->setMaterialParam(cube->position*cube->rotation*cube->scale,camera, glm::perspective(45.0f, 1280.0f / 720.0f, .1f, 1000.0f),3,glm::vec3(1,0,1),eye,glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	cube->draw();

}

void MainScene::destroyScene()
{
}


MainScene::~MainScene()
{
}
