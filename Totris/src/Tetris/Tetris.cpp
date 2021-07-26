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

void Tetris::pollKeys(GLFWwindow* window) {
	for (int i = 0; i < 8; i++) {
		int keyState = glfwGetKey(window, controlScheme[i]);
		if (keyState == GLFW_PRESS) {
			currentButtons |= (1 << i);
		}
		else if (keyState == GLFW_RELEASE) {
			currentButtons &= ~(1 << i);
			processedPresses &= ~(1 << i);
		}
	}
}

void Tetris::nextFrame(GLFWwindow* window, float timeStep) {
	pollKeys(window);
	computeFrame(timeStep);
	renderFrame();
}

void Tetris::computeFrame(float timeStep) {
	if (currentButtons & (1 << CW_ROT) && !(processedPresses & (1 << CW_ROT))) {
		activePiece->rotate(ROTATE_CW);
		processedPresses |= (1 << CW_ROT);
	}
	else if (currentButtons & (1 << ONE_EIGHTY_ROT) && !(processedPresses & (1 << ONE_EIGHTY_ROT))) {
		activePiece->rotate(ROTATE_ONE_EIGHTY);
		processedPresses |= (1 << ONE_EIGHTY_ROT);
	}
	else if (currentButtons & (1 << CCW_ROT) && !(processedPresses & (1 << CCW_ROT))) {
		activePiece->rotate(ROTATE_CCW);
		processedPresses |= (1 << CCW_ROT);
	}
	if (currentButtons & (1 << HD) && !(processedPresses & (1 << HD))) {
		cycleTetramino();
		processedPresses |= (1 << HD);
	}
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
	activePiece->rotate(ROTATE_CCW);
}
