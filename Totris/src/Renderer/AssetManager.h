#pragma once

#include <string>
#include <map>

#include "Shader.h"
#include "Texture.h"

class AssetManager {
private:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;
public:
	static Shader getShader(std::string filename);
	static void removeShader(std::string filename);
	static Texture getTexture(std::string filename);
	static void removeTexture(std::string filename);
	virtual ~AssetManager() {}
};