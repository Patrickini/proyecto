#pragma once
#include <vector>
#include <fstream>
#include "MeshOb.h"
#include "ai_Pato.h"
#include <gtc\matrix_transform.hpp>
#include "Objeto.h"
#include "Camera.h"
enum Tiles{ empty = 0, wall, pellet, _pellet, pac, fantasmon};
class Mapa
{
private:
	int mapW;
	int mapH;
	MeshOb* PacM;
	MeshOb* Fantom;
	MeshOb* Pellet;
	MeshOb* Muro;
	MeshOb* Suelo;
	Camera* pacman;
	std::vector <std::vector<Objeto>> ObArr;
	Objeto suelitoLoco;
	
	ai_Pato * material;
public:
	std::vector < std::vector < Tiles >> mapa;
	void cargarDesdeMapa(std::string mapName);
	void drawMap();
	void setup(std::string _pac, std::string _fantom, std::string _pellet, std::string _muro, std::string _suelo);
	Mapa();
	~Mapa();
};

