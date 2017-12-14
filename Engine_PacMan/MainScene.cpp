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

	map.cargarDesdeMapa("Mapa.txt");
	map.setup("PacMan.obj", "Phantom.obj", "Pellet.obj", "Wall.obj", "Piso.obj");

	triangle = new Objeto();
	MeshOb *mesh = new MeshOb();
	ai_Pato *material = new ai_Pato();
	mesh->LoadFromFile("Wall.obj");
	
	PacObj = new Objeto();
	MeshOb *PacMesh = new MeshOb();

	ai_Pato *matPAc = new ai_Pato();
	PacMesh->LoadFromFile("PacMan.obj");

	prog = new ShaderProgram();
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("shader.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("shader.f");
	prog->setShaders(vert, frag, nullptr, nullptr);
	prog->createProgram();
	material->program = prog;

	/*prog2 = new ShaderProgram();
	vert = new Shader(Shadertype::vertex);
	vert->loadFromFile("shader.v");
	frag = new Shader(Shadertype::fragment);
	frag->loadFromFile("shader.f");
	prog->setShaders(vert, frag, nullptr, nullptr);
	prog->createProgram();
	material->program = prog2;*/

	triangle->setMaterial(material);
	triangle->getMaterial()->getMaterialParam();
	triangle->setMesh(mesh);
	triangle->getMaterial()->program->activateProgram();
	triangle->translate(glm::vec3(0, 0, 100));


	PacObj->setMaterial(material);
	PacObj->getMaterial()->getMaterialParam();
	PacObj->setMesh(PacMesh);
	PacObj->getMaterial()->program->activateProgram();
	PacObj->translate(glm::vec3(0, 0, 100));
	
}

void MainScene::update()
{
}

void MainScene::draw()
{
	map.drawMap();
	//((ai_pato*)triangle->getmaterial())->setmaterialparam(glm::perspective(100.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*triangle->position*triangle->rotation*triangle->scale,glm::vec4(1.0f,0.0f,0.0f,1.0f));
	//((ai_Pato*)triangle->getMaterial())->setMaterialParam(glm::perspective(100.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*triangle->position*triangle->rotation*triangle->scale, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	////triangle->draw();
	//((ai_Pato*)PacObj->getMaterial())->setMaterialParam(glm::perspective(100.0f, 1280.0f / 720.0f, .1f, 1000.0f)*camera*PacObj->position*PacObj->rotation*PacObj->scale, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	////PacObj->draw();
}

void MainScene::destroyScene()
{
}


MainScene::~MainScene()
{
}
