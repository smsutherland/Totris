#pragma once

#include "Renderer/Renderer.h"
#include "Board.h"
#include "BagQueue.h"

class Tetris {
private:
	Board board;

	void computeFrame(float timeStep);
	void renderFrame();

	BagQueue queue;
	Tetramino currentTetramino;

	float gravity;


public:
	Tetris();
	Tetris(const Tetris& other);
	Tetris& operator=(const Tetris& rhs);
	~Tetris() {}

	void nextFrame(float timeStep);
};