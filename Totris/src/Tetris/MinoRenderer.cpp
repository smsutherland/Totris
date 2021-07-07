#include "MinoRenderer.h"

const std::vector<glm::vec3> MinoRenderer::tetraminoColors = {
	glm::vec3(1.0f, 1.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 1.0f),
	glm::vec3(0.5f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.5f, 0.0f),
	glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(1.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	glm::vec3(0.2f, 0.2f, 0.2f)
};

void MinoRenderer::registerMino(glm::vec3 color, float x, float y) {
	x *= 32;
	y *= 32;
	
	float textureData[] {
		x, y,		0.0f, 0.0f,
		x+32, y,	1.0f, 0.0f,
		x+32, y+32, 1.0f, 1.0f,
		x, y+32,	0.0f, 1.0f
	};

	for (int i = 0; i < 4*4; i++)
		minoTextureData.push_back(textureData[i]);

	float colorData[] {
		x, y,		color.x, color.y, color.z, 0.6f,
		x+32, y,	color.x, color.y, color.z, 0.6f,
		x+32, y+32, color.x, color.y, color.z, 0.6f,
		x, y+32,	color.x, color.y, color.z, 0.6f
	};

	for (int i = 0; i < 4*6; i++)
		minoColorData.push_back(colorData[i]);

	unsigned int offset = numMinos * 4;

	unsigned int indices[] {
		offset+0, offset+1, offset+2,
		offset+2, offset+3, offset+0
	};

	for (int i = 0; i < 6; i++)
		minoIndexData.push_back(indices[i]);

	numMinos++;
}

void MinoRenderer::renderMinos() {
	if (numMinos == 0)
		return;

	Renderer renderer;

	//Draw textures
	{
		VertexBuffer vertexBuffer(&minoTextureData[0], minoTextureData.size() * sizeof(float));
		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(2);

		VertexArray vertexArray;
		vertexArray.addBuffer(vertexBuffer, layout);

		IndexBuffer indexBuffer(&minoIndexData[0], minoIndexData.size());

		Shader textureShader("res/shaders/texture.shader");
		Texture texture("res/textures/discolored square.png");
		texture.bind();
		textureShader.bind();
		textureShader.setUniform1i("u_Texture", 0);

		glm::mat4 projection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		textureShader.setUniformMat4f("u_MVP", projection);

		renderer.draw(vertexArray, indexBuffer, textureShader);
	}

	//Draw colors
	{
		VertexBuffer vertexBuffer(&minoColorData[0], minoColorData.size() * sizeof(float));
		VertexBufferLayout layout;
		layout.push<float>(2);
		layout.push<float>(4);

		VertexArray vertexArray;
		vertexArray.addBuffer(vertexBuffer, layout);

		IndexBuffer indexBuffer(&minoIndexData[0], minoIndexData.size());

		Shader colorShader("res/shaders/color.shader");
		colorShader.bind();

		glm::mat4 projection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		colorShader.setUniformMat4f("u_MVP", projection);

		renderer.draw(vertexArray, indexBuffer, colorShader);
	}
}

const std::vector<glm::vec3> MinoRenderer::pieceColors(unsigned char tetramino) {
	return tetraminoColors;
}
