#include "Mapa.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Engine.h"
#include <gtc\matrix_transform.hpp>

#define en ,
#define cout( x , y ) std::getline(y en x)
void Mapa::cargarDesdeMapa(std::string mapName)
{
	std::fstream tuCulo;
	std::string miPito;
	int verga = 0;
	tuCulo.open("map.txt", std::ios_base::in);
	cout(miPito, tuCulo);
	mapW = atoi(miPito.c_str());
	cout(miPito, tuCulo);
	mapH = atoi(miPito.c_str());
	while (cout(miPito, tuCulo))
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

	glm::mat4 targetMat = glm::mat4(1.0f); 
void Mapa::drawMap()
{	
	//pacman stuff
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
		pacman->translate(glm::vec3(1, 0, 0));
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		pacman->translate(glm::vec3(-1, 0, 0));
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
		pacman->translate(glm::vec3(0, 0, 1));
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
		pacman->translate(glm::vec3(0, 0, -1));
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_D) == GLFW_PRESS)
		targetMat = glm::rotate(targetMat, 0.1f, glm::vec3(0, 1, 0));
	if (glfwGetKey(Engine::getWindow(), GLFW_KEY_A) == GLFW_PRESS)
		targetMat = glm::rotate(targetMat, -0.1f, glm::vec3(0, 1, 0));
	pacman->cameraTarget = glm::vec4(pacman->position[3].x, pacman->position[3].y, pacman->position[3].z +1.0f, 0.0f);
	pacman->cameraTarget = glm::vec4(pacman->cameraTarget,0) * targetMat;

	glm::mat4 mat = pacman->doTransformations();
	glm::vec4 vec = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	pacman->getMaterial()->setMaterialParam(2,&mat, &vec);
	pacman->draw();
	//suelito loco stuff

	mat = suelitoLoco.doTransformations();
	vec = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	suelitoLoco.getMaterial()->setMaterialParam(2,&mat, &vec);
	suelitoLoco.draw();

	for (int i = 0; i < ObArr.size(); ++i) {
		for (int j = 0; j < ObArr.at(i).size(); ++j) {
			//if (mapa[i][j] == wall)
			{
				//glm::mat4 scal = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f,1.0f, 1.0f));
				//glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3((float)j, 0.0f, i));
				//glm::vec3 eye = glm::vec3(10, 10, 10);
				//glm::vec3 target = glm::vec3(0, 0, 0);
				//glm::mat4  camera = lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
				//glm::mat4 perspective = glm::perspective(45.0f, 1280.0f / 720.0f, 0.1f, 1000.0f);
				if (mapa[i][j] == Tiles::wall)
				{
					ObArr[i][j].position = glm::translate(glm::mat4(1.0f), glm::vec3(j, 0, i));
					ObArr[i][j].scale = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));
					mat = ObArr[i][j].doTransformations();
					vec = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
					ObArr[i][j].getMaterial()->setMaterialParam(2, &mat, &vec);
					ObArr[i][j].draw();

				}
				if (mapa[i][j] == Tiles::pellet)
				{
					ObArr[i][j].position = glm::translate(glm::mat4(1.0f), glm::vec3(j, 0, i));
					ObArr[i][j].scale = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));
					mat = ObArr[i][j].doTransformations();
					vec = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
					ObArr[i][j].getMaterial()->setMaterialParam(2, &mat, &vec);
					ObArr[i][j].draw();
				}
				if (mapa[i][j] == Tiles::fantasmon)
				{
					ObArr[i][j].position = glm::translate(glm::mat4(1.0f), glm::vec3(j, 0, i));
					ObArr[i][j].scale = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));
					mat = ObArr[i][j].doTransformations();
					vec = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
					ObArr[i][j].getMaterial()->setMaterialParam(2, &mat, &vec);
					ObArr[i][j].draw();
				}
			}
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

	/*Local1.destroyShader();
	Local2.destroyShader();*/

	for (int i = 0, ij = 0; i < mapH; ++i) {
		ObArr.push_back((std::vector<Objeto>()));
		for (int j = 0, ji = 0; j < mapW; ++j) {
			if (mapa[i][j] == pellet) {
				ObArr.at(ij).push_back(Objeto());
				ObArr[ij][ji].setMesh(Pellet);
				ObArr[ij][ji].setMaterial(material);
				++ji;
			}else if (mapa[i][j] == fantasmon) {
				ObArr.at(i).push_back(Objeto());
				ObArr[ij][ji].setMesh(Fantom);
				ObArr[ij][ji].setMaterial(material);
				++ji;
			}else if (mapa[i][j] == wall) {
				ObArr.at(i).push_back(Objeto());
				ObArr[ij][ji].setMesh(Muro);
				ObArr[ij][ji].setMaterial(material);
				++ji;
			}else if (mapa[i][j] == pac) {
				ObArr.at(i).push_back(Objeto());
				ObArr[ij][ji].setMesh(Muro);
				ObArr[ij][ji].setMaterial(material);
				++ji;
			}
			else if (mapa[i][j] == empty) {
				ObArr.at(i).push_back(Objeto());
				ObArr[ij][ji].setMesh(Muro);
				ObArr[ij][ji].setMaterial(material);
				++ji;
			}

		}
		++ij;
	}
	suelitoLoco.setMesh(Suelo);
	suelitoLoco.setMaterial(material);
	pacman->setMaterial(material);
	pacman->setMesh(PacM);
	suelitoLoco.setMaterial(material);
	suelitoLoco.setMesh(Suelo);
	pacman->cameraTarget = (glm::vec4(1.0f) * pacman->position) + glm::vec4(0.0f,0.0f,1.0f,0.0f);
	pacman->cameraPerspective = glm::perspective(42.0f, (float)Engine::getWidth() / (float)Engine::getHeight(), .8f, 1000.0f);
	Engine::mainCamera = &pacman;
	pacman->position = glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0));
	suelitoLoco.scale = glm::scale(glm::mat4(1.0f), glm::vec3(mapW, 1, mapH));
	suelitoLoco.translate(glm::vec3(mapW / 2, 0, mapH / 2));
}

Mapa::Mapa()
{
}


Mapa::~Mapa()
{
}
