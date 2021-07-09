#pragma once

#include "Renderer/Renderer.h"
#include "Board.h"
#include "BagQueue.h"
#include "ActivePiece.h"

class Tetris {
private:
	Board board;

	void computeFrame(float timeStep);
	void renderFrame();

	BagQueue queue;
	ActivePiece* activePiece;

	float gravity;

	void setCurrentTetramino(Tetramino newCurrentTetramino);

public:
	Tetris();
	Tetris(const Tetris& other);
	Tetris& operator=(const Tetris& rhs);
	~Tetris() { delete activePiece; }


	void nextFrame(float timeStep);


	void cycleTetramino();
	void rotate();
};