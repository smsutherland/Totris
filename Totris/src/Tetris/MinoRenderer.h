#pragma once

#include <vector>

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

#include "Renderer/Renderer.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/Texture.h"

class MinoRenderer {
private:
	std::vector<float> minoTextureData;
	std::vector<float> minoColorData;
	std::vector<unsigned int> minoIndexData;

	unsigned int numMinos;
public:
	MinoRenderer() : numMinos(0) {} 

	void registerMino(glm::vec3 color, float x, float y);
	void renderMinos();
};

