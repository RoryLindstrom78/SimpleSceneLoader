#pragma once

struct sceneObject {
	std::string type;
	glm::vec3 Position;
	glm::vec3 Size;
	glm::vec3 Rotation;

	sceneObject(const glm::vec3& pos, const glm::vec3& sze, const glm::vec3& rot)
		: Position(pos), Size(sze), Rotation(rot) {
	}
	virtual ~sceneObject() = default;
};

struct CubeObject : public sceneObject {
	std::string textureFile = "";
	int textureID;

	CubeObject(const glm::vec3& pos, const glm::vec3& sze, const glm::vec3& rot, const std::string txtFile = "")
		:sceneObject(pos, sze, rot) {
		if (!txtFile.empty()) this->textureFile = txtFile;
	}
};

struct LightObject : public sceneObject {
	glm::vec3 Color;
	float Intensity;

	LightObject(const glm::vec3& color, const float intensity, const glm::vec3& pos, const glm::vec3& sze, const glm::vec3& rot)
		: Color(color), Intensity(intensity), sceneObject(pos, sze, rot) {
	}
};
