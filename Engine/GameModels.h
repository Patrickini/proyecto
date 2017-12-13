#pragma once
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "VertexFormat.h"
#include <vector>
#include <map>

namespace Models {

	struct Model {
		unsigned int vao;
		std::vector<unsigned int> vbos;
		Model() {}
	};

	class GameModels
	{
	public:
		GameModels();
		~GameModels();
		void createTriangleModel(const std::string& gameModelName);
		void deleteModel(const std::string &gameModelName);
		unsigned int getModel(const std::string &gameModelName);
	private:
		std::map<std::string, Model> gameModelList;
	};

}

