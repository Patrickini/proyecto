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
	triangle = new Objeto();
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
	triangle->translate(glm::vec3(0, 0, 100));
	
}

void MainScene::update()
{
}

void MainScene::draw()
{
	
	((ai_Pato*)triangle->getMaterial())->setMaterialParam(glm::perspective(100.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*triangle->position*triangle->rotation*triangle->scale,glm::vec4(1.0f,0.0f,0.0f,1.0f));

	triangle->draw();
}

void MainScene::destroyScene()
{
}


MainScene::~MainScene()
{
}
