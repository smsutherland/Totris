#include "MinoRenderer.h"

void MinoRenderer::registerMino(glm::vec3 color, float x, float y) {
	x *= 32;
	y *= 32;
	
	float minoData[] {
		x, y,			0.0f, 0.0f, color.x, color.y, color.z, 0.7f,
		x + 32, y,		1.0f, 0.0f, color.x, color.y, color.z, 0.7f,
		x + 32, y + 32, 1.0f, 1.0f, color.x, color.y, color.z, 0.7f,
		x, y + 32,		0.0f, 1.0f, color.x, color.y, color.z, 0.7f
	};

	for (int i = 0; i < 8*4; i++)
		minoVertexData.push_back(minoData[i]);

	unsigned int offset = numMinos * 4;

	unsigned int indices[] {
		offset+0, offset+1, offset+2,
		offset+2, offset+3, offset+0
	};

	for (int i = 0; i < 6; i++)
		minoIndexData.push_back(indices[i]);

	numMinos++;
}

void MinoRenderer::renderMinos(float time) {
	if (numMinos == 0)
		return;

	Renderer renderer;

	VertexBuffer vertexBuffer(&minoVertexData[0], minoVertexData.size() * sizeof(float));
	VertexBufferLayout layout;
	layout.push<float>(2);
	layout.push<float>(2);
	layout.push<float>(4);

	VertexArray vertexArray;
	vertexArray.addBuffer(vertexBuffer, layout);

	IndexBuffer indexBuffer(&minoIndexData[0], minoIndexData.size());

	Shader* shader = AssetManager::getShader("res/shaders/mino.shader");
	Texture* texture = AssetManager::getTexture("res/textures/discolored square.png");
	texture->bind();
	shader->bind();
	shader->setUniform1i("u_Texture", 0);

	glm::mat4 projection = glm::ortho(0.0f, 1080.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	shader->setUniformMat4f("u_MVP", projection);

	renderer.draw(vertexArray, indexBuffer, *shader);
}
