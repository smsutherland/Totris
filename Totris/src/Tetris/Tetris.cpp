#include "Tetris.h"

Tetris::Tetris() {
	gravity = 1.0f;
	setCurrentTetramino(queue.dequeue());
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

void Tetris::setCurrentTetramino(Tetramino newCurrentTetramino) {
	delete activePiece;
	switch (newCurrentTetramino) {
	case TetraminoO:
		activePiece = new ActivePieceO();
		break;
	case TetraminoI:
		activePiece = new ActivePieceI();
		break;
	case TetraminoT:
		activePiece = new ActivePieceT();
		break;
	case TetraminoL:
		activePiece = new ActivePieceL();
		break;
	case TetraminoJ:
		activePiece = new ActivePieceJ();
		break;
	case TetraminoS:
		activePiece = new ActivePieceS();
		break;
	case TetraminoZ:
		activePiece = new ActivePieceZ();
		break;
	case TetraminoNone:
	default:
		activePiece = nullptr;
	}
}

void Tetris::renderFrame() {
	if(activePiece != nullptr)
		activePiece->render();



	board.render();
}

void Tetris::cycleTetramino() {
	setCurrentTetramino(queue.dequeue());
}

void Tetris::rotate() {
	activePiece->rotate();
}
