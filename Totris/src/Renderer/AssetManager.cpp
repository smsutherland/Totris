#include "AssetManager.h"

std::map<std::string, Shader*> AssetManager::shaders;
std::map<std::string, Texture*> AssetManager::textures;

Shader* AssetManager::getShader(std::string filename) {
	if (shaders.find(filename) == shaders.end()) {
		Shader* newShader = new Shader(filename);
		shaders[filename] = newShader;
	}
	return shaders[filename];
}

void AssetManager::removeShader(std::string filename) {
	if (shaders.find(filename) == shaders.end()) {
		delete shaders[filename];
		shaders.erase(filename);
	}
}

Texture* AssetManager::getTexture(std::string filename) {
	if (textures.find(filename) == textures.end()) {
		Texture* newTexture = new Texture(filename);
		textures[filename] = newTexture;
	}
	return textures[filename];
}

void AssetManager::removeTexture(std::string filename) {
	if (textures.find(filename) == textures.end()) {
		delete textures[filename];
		textures.erase(filename);
	}
}

void AssetManager::clear() {
	for (auto itr = shaders.begin(); itr != shaders.end(); itr++) {
		delete itr->second;
	}
	for (auto itr = textures.begin(); itr != textures.end(); itr++) {
		delete itr->second;
	}

	shaders.clear();
	textures.clear();
}
