#pragma once

#include "Renderer/Renderer.h"
#include "MinoRenderer.h"

enum ColorEnum {
	Empty,
	Garbage,
	Yellow,
	LightBlue,
	Purple,
	Orange,
	DarkBlue,
	Green,
	Red
};

typedef unsigned char Color;

class Board {
	Color* board;

	unsigned short width, height, bufferHeight;

public:
	Board(unsigned int width_ = 10, unsigned int height_ = 20, unsigned int bufferHeight_ = 20);
	Board(const Board& other);
	Board& operator=(const Board& rhs);
	~Board();

	void render();
};
