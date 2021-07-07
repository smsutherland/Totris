#include "AssetManager.h"

std::map<std::string, Shader> AssetManager::shaders;
std::map<std::string, Texture> AssetManager::textures;

Shader AssetManager::getShader(std::string filename) {
	if (shaders.find(filename) == shaders.end())
		shaders[filename] = Shader(filename);
	return shaders[filename];
}

void AssetManager::removeShader(std::string filename) {
	if (shaders.find(filename) == shaders.end())
		shaders.erase(filename);
}

Texture AssetManager::getTexture(std::string filename) {
	if (textures.find(filename) == textures.end())
		textures[filename] = Texture(filename);
	return textures[filename];
}

void AssetManager::removeTexture(std::string filename) {
	if (textures.find(filename) == textures.end())
		textures.erase(filename);
}
