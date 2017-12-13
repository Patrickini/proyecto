#include "Mapa.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Engine.h"
#include <gtc\matrix_transform.hpp>

#define en ,
#define meter( x , y ) std::getline(y en x)
void Mapa::cargarDesdeMapa(std::string mapName)
{
	std::fstream tuCulo;
	std::string miPito;
	int verga = 0;
	tuCulo.open("map.txt", std::ios_base::in);
	meter(miPito, tuCulo);
	mapW = atoi(miPito.c_str());
	meter(miPito, tuCulo);
	mapH = atoi(miPito.c_str());
	while (meter(miPito, tuCulo))
	{
		mapa.push_back(std::vector<Tiles>());
		for (int you = 0; you < miPito.size(); ++you)
		{
			mapa.at(verga).push_back((Tiles)(miPito.at(you) - '0'));
		}
		++verga;
	}
	tuCulo.close();
}

void Mapa::drawMap()
{	
	((ai_Pato*)pacman->getMaterial())->setMaterialParam(pacman->doTransformations(), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	pacman->draw();
	((ai_Pato*)pacman->getMaterial())->setMaterialParam(pacman->doTransformations(), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	pacman->draw();
	((ai_Pato*)suelitoLoco.getMaterial())->setMaterialParam(pacman->doTransformations(), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
	suelitoLoco.draw();

	for (int i = 0; i < mapH; ++i) {
		for (int j = 0; j < mapW; ++j) {
			
				((ai_Pato*)ObArr[i][j].getMaterial())->setMaterialParam(ObArr[i][j].doTransformations(), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
				ObArr[i][j].draw();
		}
	}
	
}

void Mapa::setup(std::string _pac, std::string _fantom, std::string _pellet, std::string _muro, std::string _suelo)
{
	pacman = new Camera();
	PacM = new MeshOb();
	Fantom = new MeshOb();
	Pellet = new MeshOb();
	Muro = new MeshOb();
	Suelo = new MeshOb();
	Engine::mainCamera = &pacman;

	PacM->LoadFromFile(_pac);
	Fantom->LoadFromFile(_fantom);
	Pellet->LoadFromFile(_pellet);
	Muro->LoadFromFile(_muro);
	Suelo->LoadFromFile(_suelo);

	Shader Local1(Shadertype::fragment);
	Local1.loadFromFile("shader.f");
	Shader Local2(Shadertype::vertex);
	Local2.loadFromFile("shader.v");

	ShaderProgram* program = new ShaderProgram();
	program->setShaders(&Local2, &Local1, nullptr, nullptr);
	program->createProgram();
	program->activateProgram();

	material = new ai_Pato();
	material->program = program;
	material->getMaterialParam();
	Local1.destroyShader();
	Local2.destroyShader();

	for (int i = 0; i < mapH; ++i) {
		ObArr.push_back((std::vector<Objeto>()));
		for (int j = 0; j < mapW; ++j) {
			if (mapa[i][j] == pellet) {
				ObArr.at(i).push_back(Objeto());
				ObArr[i][j].setMesh(Pellet);
				ObArr[i][j].setMaterial(material);
			}else if (mapa[i][j] == fantasmon) {
				ObArr.at(i).push_back(Objeto());
				ObArr[i][j].setMesh(Fantom);
				ObArr[i][j].setMaterial(material);
			}else if (mapa[i][j] == wall) {
				ObArr.at(i).push_back(Objeto());
				ObArr[i][j].setMesh(Muro);
				ObArr[i][j].setMaterial(material);
			}
		}
	}
	suelitoLoco.setMesh(Suelo);
	suelitoLoco.setMaterial(material);

	pacman->cameraTarget = (glm::vec4(1.0f) * pacman->position) + glm::vec4(0.0f,0.0f,1.0f,0.0f);
	pacman->cameraPerspective = glm::perspective(100.0f, (float)Engine::getWidth() / (float)Engine::getHeight(), .1f, 1000.0f);

}

Mapa::Mapa()
{
}


Mapa::~Mapa()
{
}
