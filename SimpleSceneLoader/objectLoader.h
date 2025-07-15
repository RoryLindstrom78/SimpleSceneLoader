#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct sceneObject {
	std::string type;
	glm::vec3 Position;
	glm::vec3 Size;
	glm::vec3 Rotation;
	std::string textureFile;
	int textureID;
};

class objectLoader {
public:	
	std::ifstream inputFile;
	std::vector<sceneObject> objects;
	
	// Basic Constructor
	objectLoader(const std::string & FilePath) {
		std::ifstream inputFile(FilePath);
		if (!inputFile) {
			std::cout << "Failed to open file path!";
			return;
		}

		std::string line; 
		while (std::getline(inputFile, line)) {
			if (line.empty()) continue;
			// split by tab
			std::vector<std::string> parts = split(line, ',');
			if (parts.size() < 5) continue; // must have all fields

			sceneObject obj;
			obj.type = parts[0];
			obj.Position = parseVec3(parts[1]);
			obj.Size = parseVec3(parts[2]);
			obj.Rotation = parseVec3(parts[3]);
			obj.textureFile = parts[4];

			objects.push_back(obj);
		}

		// Debug: print all objects
		for (const auto& obj : objects) {
			std::cout << obj.type << ": pos("
				<< obj.Position.x << ", " << obj.Position.y << ", " << obj.Position.z
				<< ") size("
				<< obj.Size.x << ", " << obj.Size.y << ", " << obj.Size.z
				<< ") rotation("
				<< obj.Rotation.x << ", " << obj.Rotation.y << ", " << obj.Rotation.z
				<< ") textureFile("
				<< obj.textureFile << ")" << "\n";
		}

	}
	
	// Splits a string based on a specified delimiter
	std::vector<std::string> split(const std::string& s, char delimiter) {
		std::vector<std::string> tokens;
		std::stringstream ss(s);
		std::string item;

		while (std::getline(ss, item, delimiter)) {
			tokens.push_back(item);
		}
		return tokens;
	}

	// Parses the individual values for position, size, or rotation, into a vec3 object
	glm::vec3 parseVec3(const std::string str) {
		std::istringstream iss(str);
		float x, y, z;
		iss >> x >> y >> z;
		return glm::vec3(x, y, z);
	}
};
