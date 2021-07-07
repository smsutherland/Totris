#pragma once

#include "Renderer.h"

class Texture {
private:
	unsigned int m_rendererID;
	std::string m_filepath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_BPP;
public:
	Texture() : m_rendererID(0), m_filepath(""), m_localBuffer(nullptr), m_width(0), m_height(0), m_BPP(0) {}
	Texture(const std::string& path);
	~Texture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
};
