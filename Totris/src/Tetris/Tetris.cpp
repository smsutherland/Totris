#include "Tetris.h"

Tetris::Tetris() {
	gravity = 1.0f;
	currentTetramino = queue.dequeue();
}

Tetris::Tetris(const Tetris& other) {
	board = other.board;
}

Tetris& Tetris::operator=(const Tetris& rhs) {
	board = rhs.board;
	return *this;
}

void Tetris::nextFrame(float timeStep) {
	computeFrame(timeStep);
	renderFrame();
}

void Tetris::computeFrame(float timeStep) {

}

void Tetris::renderFrame() {




	board.render();
}