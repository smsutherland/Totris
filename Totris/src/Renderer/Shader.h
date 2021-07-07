#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

#include <GL/glew.h>

#include "glm/glm.hpp"

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	std::string m_filepath;
	unsigned int m_rendererID;
	mutable std::unordered_map <std::string, GLint> m_uniformLocationCache;

	GLint getUniformLocation(const std::string& name) const;
	unsigned int compileShader(unsigned int type, const std::string& source);
	ShaderProgramSource parseShader(const std::string& filepath);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
	Shader() : m_filepath(""), m_rendererID(0) {}
	Shader(const std::string& filepath);
	~Shader();

	void bind() const;
	void unbind() const;

	// Set uniforms
	void setUniform1i(const std::string& name, int v0);
	void setUniform1f(const std::string& name, float v0);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
};

